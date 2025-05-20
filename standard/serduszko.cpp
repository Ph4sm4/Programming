#include <iostream>
#include <math.h>
#include <wmp.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")
using namespace std;

void printXSpaces(int x)
{
    for (int i = 0; i < x; i++)
        cout << " ";
}

int main()
{
    CoInitialize(NULL);

    IWMPPlayer *player = NULL;
    CoCreateInstance(__uuidof(WindowsMediaPlayer), NULL, CLSCTX_INPROC_SERVER,
                     __uuidof(IWMPPlayer), (void **)&player);

    if (player)
    {
        IWMPMedia *media = NULL;
        player->newMedia(L"yourfile.mp3", &media);
        player->put_currentMedia(media);
        player->controls->play();

        MessageBox(NULL, L"Playing MP3. Click OK to exit.", L"MP3 Player", MB_OK);

        player->close();
        player->Release();
    }

    CoUninitialize();

        int n;
    cout << "Podaj nieparzyste n (n >= 3): ";
    cin >> n;

    if (n < 3 || n % 2 == 0)
    {
        cout << "Wrong n";
        return 1;
    }

    const int numberOfRowsUnderMain = floor(float(n) / 2.0f);

    // spaces for the first row
    printXSpaces(numberOfRowsUnderMain);
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    printXSpaces(n - 2);
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;

    // the rest rows which are going downwards

    for (int i = 0; i < numberOfRowsUnderMain; i++)
    {
        printXSpaces(numberOfRowsUnderMain - 1 - i); // from wall
        cout << "*";
        printXSpaces(n + i * 2); // miedzy pierwszym wybrzuszeniem
        cout << "*";
        printXSpaces((n - 2) - 2 * (i + 1)); // miedzy wybrzuszeniami po srodku
        if (i != numberOfRowsUnderMain - 1)
            cout << "*";
        else
            cout << "";

        printXSpaces(n + i * 2); // miedzy drugim wybrzuszeniem
        cout << "*";
        cout << endl;
    }

    int numberOfRowsLowerSection = (n / 2) * 4;

    for (int i = 0; i < numberOfRowsLowerSection; i++)
    {
        printXSpaces(i + 1); // spaces from wall
        cout << "*";
        printXSpaces(2 * n + numberOfRowsLowerSection - 3 - 2 * (i + 1));
        if (i != numberOfRowsLowerSection - 1)
            cout << "*";
        else
            cout << "";
        cout << endl;
    }

    getchar();
    getchar();

    return 0;
}