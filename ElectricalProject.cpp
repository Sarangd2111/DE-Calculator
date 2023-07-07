#include <bits/stdc++.h>
#include <fstream>

using namespace std;
#define BASE_16 16

void print_file()
{
    fstream file;
    string data;
    file.open("DE_Records.txt");

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {

            cout << line << endl;
        }
        file.close();
    }
}
class Binary_Input
{
public:
    int bnum;
    string binary;
    Binary_Input()
    {
        bnum = 0;
    }
};

class Decimal_Input
{
public:
    int dnum;
    Decimal_Input()
    {
        dnum = 0;
    }
};

class CONVERSIONS : public Binary_Input, public Decimal_Input
{
public:
    char xor_c(char a, char b) { return (a == b) ? '0' : '1'; }
    char flip(char c) { return (c == '0') ? '1' : '0'; }

    int binaryTodecimal(int bnum)
    {
        int du = bnum;
        int ans = 0;
        int x = 1;
        while (bnum > 0)
        {
            int y = bnum % 10;
            ans += x * y;
            x *= 2;
            bnum /= 10;
        }

        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Binary to Decimal:";
        op << s << "  " << du << " -> " << ans << "\n";
        op.close();
        return ans;
    }

    string binarytoGray(string binary)
    {
        string du = binary;
        string gray = "";
        gray += binary[0];

        for (int i = 1; i < binary.length(); i++)
        {
            gray += xor_c(binary[i - 1], binary[i]);
        }
        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Binary to Gray:";
        op << s << "  " << binary << " -> " << gray << "\n";
        op.close();
        return gray;
    }

    int decimalTobinary(int dnum)
    {
        int du = dnum;
        int a[10], i;
        for (i = 0; dnum > 0; i++)
        {
            a[i] = dnum % 2;
            dnum = dnum / 2;
        }
        cout << "The required Binary number is ";
        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Decimal to Binary";
        op << s << " " << du << " -> ";

        for (i = i - 1; i >= 0; i--)
        {
            op << a[i];
            cout << a[i];
        }
        op << "\n";
        op.close();
        cout << endl;
        return 0;
    }

    int decimalToctal(int dnum)
    {
        int du = dnum;
        int a[10], ans[100], i;
        for (i = 0; dnum > 0; i++)
        {
            a[i] = dnum % 8;
            dnum = dnum / 8;
        }
        cout << "The Required octal Number is ";

        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Decimal to Octal:";
        op << s << " " << du << " -> ";

        for (i = i - 1; i >= 0; i--)
        {
            op << a[i];
            cout << a[i];
        }
        op << "\n";
        op.close();
        return 0;
    }

    void decimalTohexadecimal(int dnum)
    {
        int du = dnum;
        char hexDigits[] = "0123456789ABCDEF";
        char hexadecimal[40];
        int index, remaindar;
        index = 0;

        while (dnum != 0)
        {
            remaindar = dnum % BASE_16;
            hexadecimal[index] = hexDigits[remaindar];
            dnum /= BASE_16;
            index++;
        }
        hexadecimal[index] = '\0';
        strrev(hexadecimal);
        cout << "The Required decimal Number is " << hexadecimal << endl;
        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Decimal to Hexadecimal: ";
        op << s << "  " << du << " -> " << hexadecimal << "\n";
        op.close();
    }

    int octalTodecimal(int onum)
    {
        int du = onum;
        int ans = 0;
        int x = 1;
        while (onum > 0)
        {
            int y = onum % 10;
            ans += x * y;
            x *= 8;
            onum /= 10;
        }
        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Octal to decimal";
        op << s << "  " << du << " -> " << ans << "\n";
        op.close();
        return ans;
    }

    int hexadecimalTodecimal(string v)
    {
        int ans = 0;
        int x = 1;

        int s = v.size();
        for (int i = s - 1; i >= 0; i--)
        {
            if (v[i] >= '0' && v[i] <= '9')
            {
                ans += x * (v[i] - '0');
            }
            else if (v[i] >= 'A' && v[i] <= 'F')
            {
                ans += x * (v[i] - 'A' + 10);
            }
            x *= 16;
        }
        fstream op;
        op.open("DE_Records.txt", ios::app);
        string str = "Hexadecimal to decimal";
        op << str << "  " << v << " -> " << ans << "\n";
        op.close();
        return ans;
    }

    string graytoBinary(string gray)
    {
        string binary = "";

        binary += gray[0];

        for (int i = 1; i < gray.length(); i++)
        {
            if (gray[i] == '0')
                binary += binary[i - 1];

            else
                binary += flip(binary[i - 1]);
        }
        fstream op;
        op.open("DE_Records.txt", ios::app);
        string s = "Gray to Binary";
        op << s << "  " << gray << " -> " << binary << "\n";
        op.close();
        return binary;
    }
};


class Complement : public Binary_Input
{
public:
    char flip(char c) {return (c == '0')? '1': '0';}

   void printOneAndTwosComplement(string bin)
{
    int n = bin.length();
    int i;

    string ones, twos;
    ones = twos = "";

    //  for ones complement flip every bit
    for (i = 0; i < n; i++)
        ones += flip(bin[i]);

    //  for two's complement go from right to left in
    //  ones complement and if we get 1 make, we make
    //  them 0 and keep going left when we get first
    //  0, make that 1 and go out of loop
    twos = ones;
    for (i = n - 1; i >= 0; i--)
    {
        if (ones[i] == '1')
            twos[i] = '0';
        else
        {
            twos[i] = '1';
            break;
        }
    }

    // If No break : all are 1  as in 111  or  11111;
    // in such case, add extra 1 at beginning
    if (i == -1)
        twos = '1' + twos;


    cout << "1's complement: " << ones << endl;
    cout << "2's complement: " << twos << endl;
}

};

class Binary_Arithmetic : public CONVERSIONS
{
public:
    int dec1, dec2, dec3;
    int bin1, bin2, bin3;

    Binary_Arithmetic()
    {
        cout << "Enter first binary number : ";
        cin >> bin1;
        cout << "Enter second binary number : ";
        cin >> bin2;

        dec1 = binaryTodecimal(bin1);
        dec2 = binaryTodecimal(bin2);
    }

    void addition()
    {
        dec3 = dec1 + dec2;
        decimalTobinary(dec3);
    }

    void subtraction()
    {
        dec3 = dec1 - dec2;
        decimalTobinary(dec3);
    }

    void multiplication()
    {
        dec3 = dec1 * dec2;
        decimalTobinary(dec3);
    }

    void division()
    {
        dec3 = dec1 / dec2;
        decimalTobinary(dec3);
    }
};

class BCD_Addition:public CONVERSIONS,public Binary_Arithmetic
{
public:
    CONVERSIONS cp;
    void bcd_addition(int n1,int n2){
        int a = cp.binaryTodecimal(n1);
        int b = cp.binaryTodecimal(n2);
        int c = a + b;
        if(c>9){
            int a[2];
            for(int i=0;i<2;i++)
                a[i]=c%10;
        }
        
    }

};

int main()
{
    int ch1, octal;
    string hexa, gray;
    Binary_Input B;
    Decimal_Input D;
    CONVERSIONS C;
    Complement cp;
    while (1)
    {
        cout << endl
             << "SELECT THE OPERATION" << endl
             << endl;
        cout << "(1)Number System Converter" << endl;
        cout << "(2)BCD Additions" << endl;
        cout << "(3)Complements" << endl;
        cout << "(4)Binary Arithmetic Operations" << endl;
        cout << "(5)To show previous records:\n";
        cout << "(6)EXIT!!!" << endl;

        cout << endl
             << "Enter your choice : ";
        cin >> ch1;
        cout << endl
             << endl;

        if (ch1 == 1)
        {
            int ch2;
            string choice;
            do
            {
                cout << "Select The Type of Conversion.\n\n1)Binary To Decimal. \n2)Decimal To Binary. \n3)Decimal To Octal. \n4)Decimal To Hexadecimal. \n5)Octal TO Decimal. \n6)Hexadecimal To Decimal. \n7)Binary To Gray. \n8)Gray To Binary."
                     << endl
                     << endl;
                cout << "Enter Your Choice : ";
                cin >> ch2;
                cout << endl;

                switch (ch2)
                {
                case 1:
                    cout << "Enter the binary number : ";
                    cin >> B.bnum;
                    cout << "Decimal Equivalent : " << C.binaryTodecimal(B.bnum);
                    break;

                case 2:
                    cout << "Enter the decimal number : ";
                    cin >> D.dnum;
                    C.decimalTobinary(D.dnum);
                    break;

                case 3:
                    cout << "Enter the decimal number : ";
                    cin >> D.dnum;
                    C.decimalToctal(D.dnum);
                    break;

                case 4:
                    cout << "Enter the decimal number : ";
                    cin >> D.dnum;
                    C.decimalTohexadecimal(D.dnum);
                    break;

                case 5:
                    cout << "Enter the octal number : ";
                    cin >> octal;
                    cout << "The required Decimal Number is " << C.octalTodecimal(octal);
                    break;

                case 6:
                    cout << "Enter the hexadecimal number : ";
                    cin >> hexa;
                    cout << "The required Decimal Number is " << C.hexadecimalTodecimal(hexa);
                    break;

                case 7:
                    cout << "Enter binary number : ";
                    cin >> B.binary;
                    cout << "Gray code of " << B.binary << " is "
                         << C.binarytoGray(B.binary) << endl;
                    break;

                case 8:
                    cout << "Enter gray code : ";
                    cin >> gray;
                    cout << "Binary code of " << gray << " is "
                         << C.graytoBinary(gray) << endl;
                    break;

                default:
                    cout << "Kindly Enter the right choice !!!" << endl;
                    break;

                    cout << "Do you want to Continue(Y/N) : ";
                    cin >> choice;
                }
            } while (choice == "Y" || choice == "y");
        }

        else if (ch1 == 2)
        {
            int ch = 1, num1, num2;
            BCD_Addition *task = new BCD_Addition();
            cout << "BCD Addition calculator\n";
            while (ch)
            {
                cout << "\nEnter first number : ";
                cin >> num1;
                cout << "\nEnter second number : ";
                cin >> num2;
                task->bcd_addition(num1, num2);
                cout << "\nDo you want to continue (0/1) : ";
                cin >> ch;
            }
        }

        else if (ch1 == 3)
        {
            int ch3;
            string Choice;
            do
            {
                string cnum;
                cout<<"Enter Binary Number : ";
                cin>>cnum;
                cp.printOneAndTwosComplement(cnum);
                cout << "Do you want to Continue(Y/N) : ";
                cin >> Choice;
            } while (Choice == "Y" || Choice == "y");
        }

        else if (ch1 == 4)
        {
            Binary_Arithmetic b1;
            int ch;
            string choice;
            do
            {
                cout << "(1) Biary Addition\n";
                cout << "(2) Binary Substraction\n";
                cout << "(3) Binary Multiplication\n";
                cout << "(4) Binary Division\n";
                cout << " Enter your choice:";
                cin >> ch;
                switch (ch)
                {
                case 1:
                    b1.addition();
                    break;
                case 2:
                    b1.subtraction();
                    break;
                case 3:
                    b1.multiplication();
                    break;
                case 4:
                    b1.division();
                    break;
                default:
                    cout << "\nINVALID INPUT!!! ";
                }
                cout << "\nDo you want to continue (y/n):";
                cin >> choice;

            } while (choice == "Y" || choice == "y");
        }

        else if (ch1 == 5)
        {
            print_file();
        }
        else if (ch1 == 6)
        {
            return 0;
        }
    }
    return 0;
}