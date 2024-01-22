#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct node
{
    char name[MAX_LINE_LENGTH];
    int ad_incr;
} Label;

Label p[100];
int lbl_num = 0;
// Function prototypes
void read_asm_file(const char *filename, char lines[][MAX_LINE_LENGTH], int *num_lines);
void write_output_file(const char *filename, const char *output[], int num_lines);
void assemble(char lines[][MAX_LINE_LENGTH], int num_lines, char *output[]);
int translate_instruction(char *instruction, char *machine_code, int ad_incr);

// TODO: Define any additional functions you need to implement the assembler, e.g. the symbol table.

int main(int argc, char *argv[])
{
    // Command-line argument parsing
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file.asm> <output_file.txt>\n", argv[0]);
        return 1;
    }

    lbl_num = 0;
    char input_filename[100];
    char output_filename[100];
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);
    // strcpy(input_filename, "test04.asm");
    // strcpy(output_filename, "test_out.txt");

    char lines[100][MAX_LINE_LENGTH]; // Assuming a maximum of 100 lines
    int num_lines = 0;
    read_asm_file(input_filename, lines, &num_lines); // CHANGE THE FILE NAME HERE
    // Contents copied to lines[]
    char *output[100]; // Output array of strings
    for (int i = 0; i < 100; i++)
    {
        output[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    assemble(lines, num_lines, output);
    // The translation step
    write_output_file(output_filename, (const char **)output, num_lines); // CHANGE THE FILE NAME HERE
    // COntents copied to the output file
    // Free allocated memory
    for (int i = 0; i < 100; i++)
    {
        free(output[i]);
    }

    return 0;
}

void read_asm_file(const char *filename, char lines[][MAX_LINE_LENGTH], int *num_lines)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        strcpy(lines[*num_lines], line);
        (*num_lines)++;
    }

    fclose(file);
}

void write_output_file(const char *filename, const char *output[], int num_lines)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_lines - 1; i++)
    {
        fprintf(file, "%s\n", output[i]);
    }

    fclose(file);
}

int IsPseudoOp(char temp[])
{
    if (!strcmp(".ORIG ", temp))
        return 1;
    if (!strcmp(".BLKW ", temp))
        return 1;
    if (!strcmp(".FILL ", temp))
        return 1;
    if (!strcmp(".END ", temp))
        return 1;
    if (!strcmp(".STRINGZ ", temp))
        return 1;
    return 0;
}

int IsInst(char temp[])
{
    if (!strcmp("AND ", temp))
        return 1;
    if (!strcmp("ADD ", temp))
        return 1;
    if (!strcmp("BR ", temp))
        return 1;
    if (!strcmp("BRN ", temp))
        return 1;
    if (!strcmp("BRZ ", temp))
        return 1;
    if (!strcmp("BRP ", temp))
        return 1;
    if (!strcmp("BRNZ ", temp))
        return 1;
    if (!strcmp("BRNP ", temp))
        return 1;
    if (!strcmp("BRZP ", temp))
        return 1;
    if (!strcmp("BRNZP ", temp))
        return 1;
    if (!strcmp("JSR ", temp))
        return 1;
    if (!strcmp("JSRR ", temp))
        return 1;
    if (!strcmp("JMP ", temp))
        return 1;
    if (!strcmp("RET ", temp))
        return 1;
    if (!strcmp("RTI ", temp))
        return 1;
    if (!strcmp("LD ", temp))
        return 1;
    if (!strcmp("LDI ", temp))
        return 1;
    if (!strcmp("LDR ", temp))
        return 1;
    if (!strcmp("LEA ", temp))
        return 1;
    if (!strcmp("ST ", temp))
        return 1;
    if (!strcmp("STI ", temp))
        return 1;
    if (!strcmp("STR ", temp))
        return 1;
    if (!strcmp("NOT ", temp))
        return 1;
    if (!strcmp("TRAP ", temp))
        return 1;
    return 0;
}

void assemble(char lines[][MAX_LINE_LENGTH], int num_lines, char *output[])
{
    // TODO: Implement the assembly process
    // Implement the 2-pass process described in textbook.
    // Part 1, traverse to locate the labels

    // char start_ad[5];
    int first_valid_line = 0;
    char temp[MAX_LINE_LENGTH];
    for (int first_valid_line = 0;; first_valid_line++)
    {
        for (int j = 0; j < 6; j++)
            temp[j] = lines[first_valid_line][j];
        temp[6] = 0;                 // ending signal
        if (!strcmp(".ORIG ", temp)) // .ORIG
            break;
    } // locate the 1st line
    // for (int i = 0; i < 5; i++)
    //     start_ad[i] = lines[first_valid_line][i + 7];
    // Mark the starting address

    for (int i = first_valid_line, ad_incr = 0; strcmp(".END", lines[i]); i++, ad_incr++) // i for counter
    {
        for (int j = 0; (lines[i][j] != ' ') && (lines[i][j] != 10); j++)
        {
            temp[j] = lines[i][j];
            temp[j + 1] = ' ';
            temp[j + 2] = 0;
        } // record the 1st word
        if (IsInst(temp) || IsPseudoOp(temp))
            continue;
        else
        {
            strcpy(p[lbl_num].name, temp);
            p[lbl_num].ad_incr = ad_incr;
            lbl_num++;
            continue;
        }
    }
    // Part 2, translation
    int extra_incr = 0;
    for (int i = 0; i < num_lines; i++)
    {
        extra_incr += translate_instruction(lines[i], output[i], i + 1 + extra_incr);
    }
}

char *Value2Code(int value, int outlength)
{
    char *bin = (char *)malloc(sizeof(char) * (outlength + 1));
    bin[outlength] = 0;
    for (int testbit = 1, i = outlength - 1; i >= 0; i--, testbit = testbit << 1)
        bin[i] = !(!(testbit & value)) + '0';
    return bin;
}

char *BinCode(char *data, char radix, int outlength)
{
    int value = 0;
    int digit = 0;
    for (int i = 0; data[i] != 0; i++)
        digit = i;
    if (radix == 'x')
    {
        int unit = 1;
        for (; (data[digit] != '-') && (digit >= 0); digit--, unit *= 16)
        {
            if (data[digit] <= '9')
                value += unit * (data[digit] - '0');
            if (data[digit] >= 'A')
                value += unit * (data[digit] - '7');
        }
        if (data[0] == '-')
            value = ~value + 1;
    }
    else if (radix == '#')
    {
        int unit = 1;
        for (; (data[digit] != '-') && (digit >= 0); digit--, unit *= 10)
            value += unit * (data[digit] - '0');
        if (data[0] == '-')
            value = ~value + 1;
    }
    char *bin = (char *)malloc(sizeof(char) * (outlength + 1));
    bin = Value2Code(value, outlength);
    return bin;
}

void immediatenumberprocess(char *instruction, char *machine_code, int starting_point, int nbits)
{
    char input[6];
    char *reg = (char *)malloc(sizeof(char) * 16);
    for (int i = 0; instruction[i + 1 + starting_point] != 10; i++)
    {
        input[i] = instruction[i + 1 + starting_point];
        input[i + 1] = 0;
    }
    reg = BinCode(input, instruction[starting_point], nbits);
    for (int i = 0; i < nbits; i++)
        machine_code[i + 16 - nbits] = reg[i];
}

void labelprocess(char *instruction, char *machine_code, int starting_point, int nbits, int ad_incr)
{
    char temp[MAX_LINE_LENGTH];
    for (int i = 0; instruction[i + starting_point] != 10; i++)
    {
        temp[i] = instruction[i + starting_point];
        temp[i + 1] = ' ';
        temp[i + 2] = 0;
    }
    int def_ad = 0;
    for (int i = 0;; i++)
    {
        if (!strcmp(p[i].name, temp))
        {
            def_ad = p[i].ad_incr;
            break;
        }
    }
    int offset = def_ad - ad_incr;
    char *reg = Value2Code(offset, nbits);
    for (int i = 0; i < nbits; i++)
        machine_code[i + 16 - nbits] = reg[i];
}

void registerprocess(char *instruction, char *machine_code, int starting_point, int reg_begin)
{
    char input[6];
    input[0] = instruction[starting_point];
    input[1] = 0;
    char *reg = BinCode(input, 'x', 3);
    for (int i = 0; i < 3; i++)
        machine_code[i + reg_begin] = reg[i];
}

void NumOrLabel(char *instruction, char *machine_code, int starting_point, int offset, int ad_incr)
{
    if ((instruction[starting_point] == 'x') || (instruction[starting_point] == '#'))
    { // number
        immediatenumberprocess(instruction, machine_code, starting_point, offset);
    }
    else // label
    {
        labelprocess(instruction, machine_code, starting_point, offset, ad_incr);
    }
}

int translate_instruction(char *instruction, char *machine_code, int ad_incr)
{
    int extra_incr = 0;
    int pass = 0;
    // TODO: Implement the translation of an individual instruction
    //       to machine code.
    char temp[MAX_LINE_LENGTH];
    for (int i = 0; (instruction[i] != ' ') && (instruction[i] != 10) && (instruction[i] != 0); i++)
    {
        temp[i] = instruction[i];
        temp[i + 1] = ' ';
        temp[i + 2] = 0;
    }
    int len = strlen(temp);
    int labellength = 0;
    if (!IsInst(temp) && !IsPseudoOp(temp))
    {
        labellength = len;
        for (int i = 0; (instruction[i + labellength] != ' ') && (instruction[i + labellength] != 10) && (instruction[i + labellength] != 0); i++)
        {
            temp[i] = instruction[i + labellength];
            temp[i + 1] = ' ';
            temp[i + 2] = 0;
        }
        len += strlen(temp);
    }
    // len is where the instruction read-in reaches
    if (IsPseudoOp(temp))
    {
        if (!strcmp(".END ", temp))
            return 0;
        if (!strcmp(".ORIG ", temp) || !strcmp(".FILL ", temp))
        {
            char input[6];
            for (int i = 0; instruction[i + 7 + labellength] != 10; i++)
            {
                input[i] = instruction[i + 7 + labellength];
                input[i + 1] = 0;
            }
            char *reg = BinCode(input, instruction[6 + labellength], 16);
            for (int i = 0; i < 16; i++)
                machine_code[i] = reg[i];
        }
        if (!strcmp(".BLKW ", temp))
        {
            int value = 0;
            int digit = 0;
            char radix = instruction[6 + labellength];
            char data[7];
            for (int i = 0; instruction[7 + labellength + i] != 10; i++)
            {
                data[i] = instruction[i + 7 + labellength];
                data[i + 1] = 0;
            }
            for (int i = 0; data[i] != 0; i++)
                digit = i;
            if (radix == 'x')
            {
                int unit = 1;
                for (; (data[digit] != '-') && (digit >= 0); digit--, unit *= 16)
                {
                    if (data[digit] <= '9')
                        value += unit * (data[digit] - '0');
                    if (data[digit] >= 'A')
                        value += unit * (data[digit] - '7');
                }
                if (data[0] == '-')
                    value = ~value + 1;
            }
            if (radix == '#')
            {
                int unit = 1;
                for (; (data[digit] != '-') && (digit >= 0); digit--, unit *= 10)
                    value += unit * (data[digit] - '0');
                if (data[0] == '-')
                    value = ~value + 1;
            }
            extra_incr = value - 1;
            for (int i = 0; i < value; i++)
            {
                for (int j = 0; j < 16; j++)
                {
                    machine_code[i * 17 + j] = '0';
                }
                machine_code[i * 17 + 17 - 1] = 10;
            }
            machine_code[value * 17 - 1] = 0;
            pass++;
        }
        if (!strcmp(".STRINGZ ", temp))
        {
            char stringZ[MAX_LINE_LENGTH];
            for (int i = 0; instruction[i + 10 + labellength] != '"'; i++)// I FORGOT!!!
            {
                stringZ[i] = instruction[i + 10 + labellength];// I FORGOT!!!
                stringZ[i + 1] = 0;
            }
            char *bin;
            int xxx = strlen(stringZ);
            for (int i = 0; i <= xxx; i++)
            {
                bin = Value2Code((int)stringZ[i], 16);
                for (int j = 0; j < 16; j++)
                {
                    machine_code[i * 17 + j] = bin[j];
                }
                machine_code[i * 17 + 17 - 1] = 10;
            }
            machine_code[strlen(stringZ) * 17 + 17 - 1] = 0;
            pass++;
            extra_incr = strlen(stringZ);
        }
    }
    if (IsInst(temp))
    {
        if (!strcmp("ADD ", temp) || !strcmp("AND ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = (temp[1] == 'N') ? '1' : '0';
            machine_code[2] = '0';
            machine_code[3] = '1';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            registerprocess(instruction, machine_code, 9 + labellength, 7);

            if (instruction[12 + labellength] == 'R') // Register
            {
                machine_code[10] = '0';
                machine_code[11] = '0';
                machine_code[12] = '0';
                registerprocess(instruction, machine_code, 13 + labellength, 13);
            }
            else // immediate number
            {
                machine_code[10] = '1';
                immediatenumberprocess(instruction, machine_code, 12 + labellength, 5);
            }
        }
        else if (!strcmp("BR ", temp) || !strcmp("BRN ", temp) || !strcmp("BRZ ", temp) || !strcmp("BRP ", temp) || !strcmp("BRNZ ", temp) || !strcmp("BRNP ", temp) || !strcmp("BRZP ", temp) || !strcmp("BRNZP ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '0';
            machine_code[2] = '0';
            machine_code[3] = '0';
            machine_code[4] = '0';
            machine_code[5] = '0';
            machine_code[6] = '0';
            if (!strcmp("BR ", temp) || !strcmp("BRNZP ", temp))
            {
                machine_code[4] = '1';
                machine_code[5] = '1';
                machine_code[6] = '1';
            }
            if (!strcmp("BRN ", temp) || !strcmp("BRNZ ", temp) || !strcmp("BRNP ", temp))
                machine_code[4] = '1';
            if (!strcmp("BRZ ", temp) || !strcmp("BRNZ ", temp) || !strcmp("BRZP ", temp))
                machine_code[5] = '1';
            if (!strcmp("BRP ", temp) || !strcmp("BRZP ", temp) || !strcmp("BRNP ", temp))
                machine_code[6] = '1';
            NumOrLabel(instruction, machine_code, len + labellength, 9, ad_incr);
        }
        else if (!strcmp("JMP ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '1';
            machine_code[2] = '0';
            machine_code[3] = '0';
            machine_code[4] = '0';
            machine_code[5] = '0';
            machine_code[6] = '0';
            registerprocess(instruction, machine_code, 5 + labellength, 7);
            machine_code[10] = '0';
            machine_code[11] = '0';
            machine_code[12] = '0';
            machine_code[13] = '0';
            machine_code[14] = '0';
            machine_code[15] = '0';
        }
        else if (!strcmp("JSR ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '1';
            machine_code[2] = '0';
            machine_code[3] = '0';
            machine_code[4] = '1';
            NumOrLabel(instruction, machine_code, 4 + labellength, 11, ad_incr);
        }
        else if (!strcmp("JSRR ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '1';
            machine_code[2] = '0';
            machine_code[3] = '0';
            machine_code[4] = '0';
            machine_code[5] = '0';
            machine_code[6] = '0';
            registerprocess(instruction, machine_code, 6 + labellength, 7);
            machine_code[10] = '0';
            machine_code[11] = '0';
            machine_code[12] = '0';
            machine_code[13] = '0';
            machine_code[14] = '0';
            machine_code[15] = '0';
        }
        else if (!strcmp("LD ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '0';
            machine_code[2] = '1';
            machine_code[3] = '0';
            registerprocess(instruction, machine_code, 4 + labellength, 4);
            NumOrLabel(instruction, machine_code, 7 + labellength, 9, ad_incr);
        }
        else if (!strcmp("LDI ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '0';
            machine_code[2] = '1';
            machine_code[3] = '0';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            NumOrLabel(instruction, machine_code, 8 + labellength, 9, ad_incr);
        }
        else if (!strcmp("LDR ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '1';
            machine_code[2] = '1';
            machine_code[3] = '0';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            registerprocess(instruction, machine_code, 9 + labellength, 7);
            NumOrLabel(instruction, machine_code, 12 + labellength, 6, ad_incr);
        }
        else if (!strcmp("LEA ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '1';
            machine_code[2] = '1';
            machine_code[3] = '0';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            NumOrLabel(instruction, machine_code, 8 + labellength, 9, ad_incr);
        }
        else if (!strcmp("NOT ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '0';
            machine_code[2] = '0';
            machine_code[3] = '1';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            registerprocess(instruction, machine_code, 9 + labellength, 7);
            machine_code[10] = '1';
            machine_code[11] = '1';
            machine_code[12] = '1';
            machine_code[13] = '1';
            machine_code[14] = '1';
            machine_code[15] = '1';
        }
        else if (!strcmp("RET ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '1';
            machine_code[2] = '0';
            machine_code[3] = '0';
            machine_code[4] = '0';
            machine_code[5] = '0';
            machine_code[6] = '0';
            machine_code[7] = '1';
            machine_code[8] = '1';
            machine_code[9] = '1';
            machine_code[10] = '0';
            machine_code[11] = '0';
            machine_code[12] = '0';
            machine_code[13] = '0';
            machine_code[14] = '0';
            machine_code[15] = '0';
        }
        else if (!strcmp("RTI ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '0';
            machine_code[2] = '0';
            machine_code[3] = '0';
            machine_code[4] = '0';
            machine_code[5] = '0';
            machine_code[6] = '0';
            machine_code[7] = '0';
            machine_code[8] = '0';
            machine_code[9] = '0';
            machine_code[10] = '0';
            machine_code[11] = '0';
            machine_code[12] = '0';
            machine_code[13] = '0';
            machine_code[14] = '0';
            machine_code[15] = '0';
        }
        else if (!strcmp("ST ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '0';
            machine_code[2] = '1';
            machine_code[3] = '1';
            registerprocess(instruction, machine_code, 4 + labellength, 4);
            NumOrLabel(instruction, machine_code, 7 + labellength, 9, ad_incr);
        }
        else if (!strcmp("STI ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '0';
            machine_code[2] = '1';
            machine_code[3] = '1';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            NumOrLabel(instruction, machine_code, 8 + labellength, 9, ad_incr);
        }
        else if (!strcmp("STR ", temp))
        {
            machine_code[0] = '0';
            machine_code[1] = '1';
            machine_code[2] = '1';
            machine_code[3] = '1';
            registerprocess(instruction, machine_code, 5 + labellength, 4);
            registerprocess(instruction, machine_code, 9 + labellength, 7);
            NumOrLabel(instruction, machine_code, 12 + labellength, 6, ad_incr);
        }
        else if (!strcmp("TRAP ", temp))
        {
            machine_code[0] = '1';
            machine_code[1] = '1';
            machine_code[2] = '1';
            machine_code[3] = '1';
            machine_code[4] = '0';
            machine_code[5] = '0';
            machine_code[6] = '0';
            machine_code[7] = '0';
            immediatenumberprocess(instruction, machine_code, 5 + labellength, 8);
        }
    }
    if (!pass)
        machine_code[16] = 0;
    return extra_incr;
}
