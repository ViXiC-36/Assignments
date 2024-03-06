#ifndef _HUFFMANTREE_CPP_
#define _HUFFMANTREE_CPP_

#include <stdio.h>
#include <stdlib.h>
// #include "showgt.h"

// 编码的最大长度
#define MCL 30 // maximal length of one single code
// 定义叶节点数,8bit的unsigned char
#define leefNum 256 // the number of leadf nodes
// 定义结点总数，2n-1
#define nodenuM 511 // the number of nodes

// Huffman Tree Node
typedef struct HuffNode
{
    int id;
    long weight;
    struct HuffNode *parent, *lchild, *rchild;
} HTNode;

// table of info to be encoded(matching the leaf nodes)
typedef struct
{
    long long code; // 前面都是0，最后len位是编码
    long long len;       // 编码长度
} HCode;           // 哈夫曼编码表

void printHTree1(HTNode *ht);

// w[] stores the weights of the leaves
int CreateHTree(HTNode ht[], long *w)
{
    long all_w = 0;  // all weights' sum
    int numZero = 0; // the number of the not appearing characters
    for (int i = 0; i < nodenuM; i++)
    {
        ht[i].id = i; // give each node an identity
        ht[i].parent = NULL;
        ht[i].lchild = NULL;
        ht[i].rchild = NULL; // place empty
        ht[i].weight = 0;    // place zero
        if (i < leefNum)
        {
            ht[i].weight = w[i];
            if (w[i] == 0)
                numZero++;
            all_w += w[i];
        }
    } // initialize the huffman tree, each node seperated from the others

    int i = leefNum, j;
    long min1, min2;
    while (i < nodenuM - numZero)
    {
        min1 = all_w + 10; // set the maximal weight
        min2 = all_w + 10;
        unsigned bldbro1, bldbro2; // two blood brothers to be matched with their parent
        for (j = 0; j < i; j++)
        {
            if (ht[j].weight == 0) // ignore the nodes with 0 weight
                continue;
            if (ht[j].parent == NULL)
            {
                /*Find a weight that's less than min1
                min2 <- min1; min1 <- the weight*/
                if (ht[j].weight < min1)
                {
                    bldbro2 = bldbro1;
                    min2 = min1;
                    bldbro1 = j;
                    min1 = ht[j].weight;
                }
                else
                {
                    // min1 <= the w < min2
                    if (ht[j].weight < min2)
                    {
                        bldbro2 = j;
                        min2 = ht[j].weight;
                    }
                }
            }
        }
        // yeogiggaji_k the least two blood brothers are found
        HTNode *p = NULL;
        HTNode *q = NULL;
        p = &ht[i];

        q = &ht[bldbro1];
        p->lchild = q;
        q->parent = p;

        q = &ht[bldbro2];
        p->rchild = q;
        q->parent = p;
        p->weight = min1 + min2;
        i++;
        // for (i = 0; i < nodenuM; i++)
        //     printf("[%d]", ht[i].id);
    }
    return nodenuM - numZero - 1;
}

// Pre-order traverse print function
void printHTree0(HTNode t[], int ridx)
{
    if (ridx >= 0)
    {
        if (t[ridx].weight > 0)
            printf("%3d->%5ld\n", (ridx < leefNum) ? t[ridx].id : t[ridx].id + leefNum, t[ridx].weight);
        printHTree0(t, t[ridx].lchild->id);
        printHTree0(t, t[ridx].rchild->id);
    }
}

// Print in the form of array(used for debugging)
void printHTree1(HTNode ht[])
{
    printf("\nHuffman Tree (in the order of array):\n");
    for (int i = 0; i < nodenuM; i++)
    {
        if (i < leefNum)
            printf("%2x %3d -> %5d => p:%3d lc:%3d rc:%3d\n", ht[i].id, ht[i].id, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
        else
            printf("%2x %3d -> %5d => p:%3d lc:%3d rc:%3d\n", ht[i].id, ht[i].id + leefNum, ht[i].weight, ht[i].parent, ht[i].lchild, ht[i].rchild);
    }
}

unsigned char *Parsefile(const char filename[], long *w, long *fsize)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Failed to open the file!\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    *fsize = ftell(fp);
    rewind(fp);
    unsigned char *dataArray; // to load the data of the file
    dataArray = (unsigned char *)malloc(sizeof(unsigned char) * (*fsize));
    if (!dataArray)
    {
        printf("No enough memory to create dataArray!\n");
        exit(0);
    }
    fread(dataArray, sizeof(unsigned char), *fsize, fp);
    fclose(fp);

    for (int i = 0; i < leefNum; i++)
        w[i] = 0; // clear up ALL the values of weight
    for (int i = 0; i < *fsize; i++)
        w[dataArray[i]]++; // weight++ if the correspongding char appears
    return dataArray;      // contents saved here
}

void GetCode(HTNode ht[], int c, unsigned *code1, int *clen1)
{
    int clen = 0;      // code length
    long long code = 0; // code

    long long size = sizeof(code);             // bits for each code
    unsigned mask = 1 << (size * 8 - 1); // used to set a highest digit to be 1

    int parent_id = ht[c].parent->id; // wrong, 0 but should be 256
    while (parent_id >= 0)
    {
        code = code >> 1;
        code = (ht[parent_id].lchild->id == c) ? code : (code | mask);
        clen++;
        c = parent_id;
        parent_id = (ht[c].parent) ? ht[c].parent->id : -1;
    }

    // The first "clen" digits of "code" is its huffman code. Move them to the rightmost
    code = code >> (size * 8 - clen);
    // printf("0x%x-%d\n",code,clen);
    *code1 = code; // 返回值
    *clen1 = clen; // 返回值
}

// Complete the Huffman encode table
void GenHCodes(HCode hc[], HTNode ht[])
{
    for (int i = 0; i < leefNum; ++i)
        if (ht[i].weight > 0)
            GetCode(ht, i, &(hc[i].code), &(hc[i].len));
}

/*Encode & Decode*/
// Encode
void Encode(unsigned char *ori, long olen, unsigned char *newcode, long *newlen, HCode hc[])
{
    int sizecode = sizeof(long long);
    long i = 0;
    long j = 0;
    newcode[j] = 0;
    long long code;
    int len;
    int usedbits = 0; // used bits in newcode[j]
    while (i < olen)
    {                     // Process the original data respectively
        int idx = ori[i]; // get the id of hc
        code = hc[idx].code;
        len = hc[idx].len;
        while (len + usedbits >= 8)
        { // code left moves usedbits, then bitewise OR with newcode[j]
            long long code1 = code >> (len + usedbits - 8);
            newcode[j] = newcode[j] | code1; // 填满前一个编码字符
            len = len + usedbits - 8;        // code现在有效长度
            usedbits = 0;
            newcode[++j] = 0;
        }
        //
        code = code & ((1 << len) - 1);      // code和后面k个1，其它全为0的数据进行与，保留后面len位
        code = code << (8 - len - usedbits); // 向前移动若干位
        newcode[j] = newcode[j] | code;
        usedbits = len + usedbits;
        i++;
    }
    *newlen = j + 1;
}

void zip(char fout[], HTNode ht[], int root_id, HCode hc[], unsigned char *content, long fsize)
{
    unsigned char *zipContent;
    long zipsize;
    zipContent = (unsigned char *)malloc(sizeof(unsigned char) * (fsize + 10000));
    if (!zipContent)
    {
        printf("Not enough memory to create zipContent!\n");
        exit(0);
    }
    Encode(content, fsize, zipContent, &zipsize, hc);

    FILE *fp = fopen(fout, "wb");
    if (fp == NULL)
    {
        printf("Failed to write the zip file!\n");
        exit(0);
    }
    long ht_size = sizeof(HTNode) * nodenuM;
    fwrite(&ht_size, sizeof(ht_size), 1, fp);
    fwrite(&zipsize, sizeof(zipsize), 1, fp);               // 保存编码内容的大小
    fwrite(&fsize, sizeof(fsize), 1, fp);                   // 保存原始内容的大小
    fwrite(&root_id, sizeof(root_id), 1, fp);               // 保存哈夫曼树根节点的下标
    fwrite(ht, sizeof(HTNode), nodenuM, fp);                // 保存哈夫曼树 ，解码要用到
    fwrite(zipContent, sizeof(unsigned char), zipsize, fp); // 保存编码后的内容
    fclose(fp);

    free(zipContent); // 释放文件内容
    printf("Condensed file %s was generated successfully!\n", fout);
}

void unzip(char zfile[], char ofile[])
{
    FILE *fp = fopen(zfile, "rb");

    // printf("\nA\n");

    if (fp == NULL)
    {
        printf("无法打开压缩文件进行读取!\n");
        exit(0);
    }
    long ht_size1, zipsize1, fsize1;
    int root_id;                               // 树的根结点下标
    fread(&ht_size1, sizeof(ht_size1), 1, fp); // 哈夫曼树的大小(字节数）
    fread(&zipsize1, sizeof(zipsize1), 1, fp); // 压缩后内容的大小
    fread(&fsize1, sizeof(fsize1), 1, fp);     // 被压缩内容的大小
    fread(&root_id, sizeof(root_id), 1, fp);   // 哈夫曼树根的下标

    // printf("\nX\n");

    unsigned char *zcontent = (unsigned char *)malloc(zipsize1); // 存放读取的编码数据
    unsigned char *ocontent = (unsigned char *)malloc(fsize1);   // 解码后的数据
    HTNode ht1[nodenuM];
    fread(ht1, ht_size1, 1, fp);      // 读取哈夫曼树
    fread(zcontent, zipsize1, 1, fp); // 读取编码数据
    fclose(fp);

    // printf("\nB\n");

    fp = fopen(ofile, "wb");
    if (fp == NULL)
    {
        printf("无法打开解压后文件进行解压!\n");
        exit(0);
    }

    // printf("\nC\n");

    int idx = root_id;   // 从根开始
    int j, k = 0, i = 0; // zcontent的下标 k,ocontent的下标i
    while (i < fsize1)
    {            // 依次写入解压后数据的每个字节
        j = 128; // 10000000
        while (j > 0)
        {
            if ((zcontent[k] & j) > 0)
            { // 向右走 1
                if (ht1[idx].rchild == NULL)
                {
                    ocontent[i++] = ht1[idx].id;
                    idx = root_id; // 解码了下一个字符的第一个bit
                    fprintf(fp, "%c", ocontent[i - 1]);
                    if (i >= fsize1) // 解码结束
                        break;
                    j = j << 1;
                }
                else
                    idx = ht1[idx].rchild->id;
            }
            else
            { // 向左走 0
                if (ht1[idx].lchild == NULL)
                {
                    ocontent[i++] = ht1[idx].id;
                    idx = root_id; // 解码了下一个字符的第一个bit
                    fprintf(fp, "%c", ocontent[i - 1]);
                    if (i >= fsize1) // 解码结束
                        break;
                    j = j << 1;
                }
                else
                    idx = ht1[idx].lchild->id;
            }
            j = j >> 1; // j控制while循环8次，求出zcontent[k]的每一位
        }
        if (i >= fsize1) // 解码结束
            break;
        k++; // 准备读取下一个字符
    }
    fclose(fp);
    free(ocontent);
    free(zcontent);
    printf("The file %s has been extracted as %s successfully!\n", zfile, ofile);
}

int check(char file1[], char file2[])
{
    FILE *fp1 = fopen(file1, "r"), *fp2 = fopen(file2, "r");
    unsigned fsize1, fsize2;
    fseek(fp1, 0, SEEK_END);
    fseek(fp2, 0, SEEK_END);
    fsize1 = ftell(fp1);
    fsize2 = ftell(fp2);
    rewind(fp1);
    rewind(fp2);
    if (fsize1 != fsize2)
        return 0;
    char c1, c2;
    for (unsigned i = 0; i < fsize1; ++i)
    {
        fread(&c1, 1, 1, fp1);
        fread(&c2, 1, 1, fp2);
        if (c1 != c2)
            return printf("at fsize = %d, c1 is %d, c2 is %d\n", i, c1, c2);
    }
    fclose(fp1);
    fclose(fp2);
    return 1;
}

int main()
{
    HTNode ht[nodenuM]; // 结构体数组，表示哈夫曼树 : id,w,parent,lchild,rchild，用于生成编码表和解压
    HCode hc[leefNum];  // 结构体数组，表示哈夫曼编码表 :code,len，用于编码文件

    /*** 读取文件，分析文件字符出现规律，构建哈夫曼树，生成哈夫曼编码表 ***/
    char infile[] = "test";
    long wDist[256]; // 保存字符的分布（字符在文件中出现的次数）
    long fsize;      // 文件长度
    // 获取文件内容，分析待压缩文件，返回权值向量wDist,文件内容content和长度fsize
    unsigned char *content = Parsefile(infile, wDist, &fsize);
    int root_id = CreateHTree(ht, wDist); // root是哈夫曼树ht的根结点的下标
    GenHCodes(hc, ht);                    // 生成完整的编码表,用于编码文件

    // 下面的代码用于测试哈夫曼树
    // printHtree1(ht); //将哈夫曼树按数组打印出来
    // printHtree0(ht,root_id); //先序遍历哈夫曼树
    // saveTree(ht,root_id,"aa1.html"); //图形展示哈夫曼树

    // 编码，压缩文件,写入文件 fout
    char zfile[256] = "mypdf.txt";
    zip(zfile, ht, root_id, hc, content, fsize);

    /*************************** 以下为解码内容 ****************************/
    char ofile[256] = "ntest";
    unzip(zfile, ofile);

    check("test", "ntest"); 

    free(content);
    return 1;
}

#endif