
#include <iostream>

int main()
{
    char str[256];
    char s[256] = "\n";
    int Index; // откуда
    int Len; // длина копирования
    char Probel[] = " ";
    char f[] = "%s";
    char fd[] = "%d";
    std::cout << "Enter your string:";
    char forIndex[256] = "Index for copy: ";
    char forLen[256] = "Length for copy: ";

    __asm
    {
        lea esi, str
        push esi

        lea ecx, f
        push ecx
        call scanf
        add esp, 8

        lea ebx, forIndex
        push ebx

        lea ecx, f
        push ecx
        call printf
        add esp, 8

        lea ebx, Index
        push ebx

        lea ecx, fd
        push ecx
        call scanf
        add esp, 8

        lea ebx, forLen
        push ebx

        lea ecx, f
        push ecx
        call printf
        add esp, 8

        lea ebx, Len
        push ebx

        lea ecx, fd
        push ecx
        call scanf
        add esp, 8

        lea ecx, fd
        mov ecx, -1
        dec esi

        push edx
        mov edx, Index

        lea ecx, fd
        mov ecx, -1
        dec esi

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

            StartCopy :
        cmp Index, 0
            jge LengthCopy

            mov Index, 0

            LengthCopy :
            cmp Len, 0
            jl StrNoChange

            IndexBiggerLength :
        cmp Index, ecx
            jg StrNoChange

            add edx, Len

            CheckLengthCopy :

        cmp edx, ecx
            jbe Later
            mov edx, ecx

            Later :
        add esp, 8
            mov ecx, -1
            dec esi

            lea esi, [str]
            lea edi, [s]
            push edi
            dec esi

            mov edx, Index

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

            StrNoChange :
        add esp, 8
            mov ecx, -1
            dec esi
            lea esi, [Probel]
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
    std::cout << "String: ";
    std::cout << s;
}

