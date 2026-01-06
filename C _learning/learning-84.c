#include<stdio.h>
	int main(void)
	{  
	  /*********Begin*********/
	  int num ;
      scanf("%d",&num);
      int temp_num = num;
      int count = 0;
      while(temp_num != 0)
      {
        temp_num =  temp_num / 10;
        count++;
      }
      
      temp_num = num;
      int result = 1;
      for(int i = 0; i < count;i++)
      {
        int wei_num = temp_num % 10;
        result = result * wei_num;
        temp_num = temp_num / 10;
      }
      printf("%d",result);
	  
	  /*********End**********/ 
       return 0;
	}
