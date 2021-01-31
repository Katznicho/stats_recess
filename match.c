#include <stdio.h>
///////////////////////////////////////////////
    float median(int array_name[],int size){ //median(arr_name,size);
       // puts("Started");
        int i,j;
        for (i = 0; i < size-1; i++) {
           /* code here */ 
           for (j = i+1; j < size; j++) {
              /* code here */ 
              if (array_name[j] < array_name[i]) {
                 /* code here */ 
                 int temp = array_name[j+1];
                 array_name[j] = array_name[j+1];
                array_name[j] = temp;
              }
           }
        }
        
        if(size%2==0){
            return (array_name[(size/2)-1] +array_name[(size/2)])/2;
        }else {
           /* code here */ 
           return array_name[(size/2)];
        }
    }
   /////////////////////////////////////////////////////     ////////////////
    void main(){
       int array[] = {38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38};
        printf("The median value is %.1f\n",median(array,4));

    }
