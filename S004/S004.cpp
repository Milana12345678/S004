
#include <iostream>

int main()
{
    char m1[] = "Enter your string\n";
    char str[256];
    char s[256] = "\0";
    int First = 2; // с какого индекса копируем
    int Len = 4; // длина копирования
    char f[] = "%s";
    __asm
    {
        lea ebx, m1
        push ebx
        lea ecx, f
        push ecx
        call printf
        add esp, 8

        lea ebx, str
        push ebx
        lea ecx, f

        push ecx
        call scanf
        add esp, 8

        

        push edx
        mov edx, First

        lea ebx, str
        push ebx
        dec ebx

        LengthStr :
        inc ecx
            inc ebx
            mov al, [ebx]
            cmp al, 0
            jnz LengthStr
            push ecx

            StartCopy : // Начало копирования(начиная с нуля)
        cmp First, 0
            jl StrNoChange

            LengthCopy : //Длина копирования
        cmp Len, 0
            jl StrNoChange

            FirstBiggerLength :
        cmp First, ecx
            jg StrNoChange

            add edx, Len

            CheckLengthCopy : 
        add ecx, 1
            cmp edx, ecx
            jg StrNoChange

            add esp, 8
            mov ecx, -1
            dec esi

            lea esi, [str]
            lea edi, [s]
            push edi
            dec esi

            mov edx, First

            Write :
        inc esi
            inc ecx
            cmp ecx, edx
            jne Write

            add edx, Len

            ContinueWrite :
        inc ecx
            lodsb
            stosb
            cmp ecx, edx
            jne ContinueWrite

            jmp End

            StrNoChange : // строка без изменений
            add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [str]
            lea edi, [s]
            push edi

            ContinueNoChange :
        lodsb
            stosb
            cmp al, 0
            jnz ContinueNoChange

            End :
        pop edi
            pop esi
    }
    std::cout << s;
}

