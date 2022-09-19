#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

#define SECTOR_SIZE 512

int main()
{
    string device = "\\\\.\\E:";
    FILE *fp = fopen("\\\\.\\E:", "rb");
    if (fp == NULL)
    {
        printf("Image does not exist\n");
        return 0;
    }
    // ifstream infile(device.c_str(), ios::in, ios::binary);
    fseek(fp, 0, SEEK_SET);
    char teste[SECTOR_SIZE];
    int lido = fread(teste, sizeof(teste), 1, fp);
    printf("opened. %s", teste);
    fclose(fp);

    cout << endl;
    for (unsigned i = 0; i < 512; i++)
    {
        cout << hex << (0xFF & (unsigned int)teste[i]) << " ";
    }

    cout << endl;
    cout << hex << (0xFF & (unsigned int)teste[13]) << endl;
    cout << hex << (0xFF & (unsigned int)teste[14]) << endl;
    cout << hex << (0xFF & (unsigned int)teste[15]) << endl;
    cout << hex << (0xFF & (unsigned int)teste[28]) << " ";
    cout << hex << (0xFF & (unsigned int)teste[29]) << " ";
    cout << hex << (0xFF & (unsigned int)teste[30]) << " ";
    cout << hex << (0xFF & (unsigned int)teste[31]) << endl;

    cout << dec << (((0xFF & (unsigned int)teste[14]) << 8 | 0xFF & (unsigned int)teste[15])) << endl;

    //#eb5890 4d53444f53 352e3002 8ae120000f8003f0ff000000e07c0291f0000002000106000000000000080029fc4c5ae4e4f204e414d4520202020464154333220202033c98ed1bcf47b8ec18ed9bd07c885640884e28a5640b441bbaa55cd13721081fb55aa75af6c11745fe462eb2d8a5640b48cd13735b9ffff8af166fb6c64066fb6d180e23ff7e286cdc0ed64166fb7c966f7e1668946f8837e1607539837e2a07733668b461c6683c0cbb080b910e82c0e9a83a1f87d80c47c8bf0ac84c074173cff749b4ebb70cd10ebeea1fa7debe4a17d80ebdf98cd16cd196660807e20f84200666a06650653666810010b4428a56408bf4cd136658665866586658eb33663b46f8723f9eb2a6633d266fb74e1866f7f1fec28aca668bd066c1ea10f77693fa7f0048841fc3f67f000000000062171fc3f67f00100000000000000000000000000000000f9141fc3f67f0048841fc3f67f0040841fc3f67f00f0169416f11008000000000000000bb171fc3f67f0020151fc3f67f00800000000000000011011000006879416f110046d8e593fa7f00d8169416f110000000000

    // char buffer[32];
    // int fileID = open("\\\\.\\F:", O_RDONLY);

    // // Read first 512 bytes -> boot sector
    // // POR QUE Q O READ RETORNA -1 SEMPRE??????????
    // int count = read(fileID, buffer, 1);
    // if (!count)
    // {
    //     printf("Error (%d) - Boot Sector \n", count);
    //     exit(0);
    // }
    // printf("%d\n", fileID);
    // printf("%d\n", count);
    // close(fileID);
    return 0;
}