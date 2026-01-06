#include<stdio.h>
int main()
{
    FILE *file1 = fopen ("D:\\Hail-v1.9.0.apk","rb");
    FILE *file2 = fopen ("D:\\datovm\\showcopy.apk","wb");

    int n;
    char arr[1024];
    while(n=(fread(arr,1,1024,file1) != 0))
    {
       fwrite(arr,1,n,file2);
    }

    fclose(file1);
    fclose(file2);

    return 0;
}