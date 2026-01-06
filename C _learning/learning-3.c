 #include<stdio.h>
 int main()
 {
    double length;
    double width;
    double height;

    printf("键盘录入三个小数，分别是长，宽，高 \n");
    scanf("%lf %lf %lf",&length,&width,&height);
    
    double areaA = length * width;
    double areaB = height * width;
    double areaC = length * height;

    printf("A面的面积位为：%.2lf \n",areaA);
    printf("B面的面积位为：%.2lf \n",areaB);
    printf("C面的面积位为：%.2lf \n",areaC);

    double volume = length * width * height;
    printf("长方体的体积为：%.3f \n",volume);
    return 0;
}
