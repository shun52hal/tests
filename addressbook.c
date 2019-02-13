
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char name[256];
    int gender;
    int age;
    int birthday;
    char address[1000];
    
} address_book;

void address_book_inputs(address_book *data);/*入力関数のプロトタイプ宣言*/
void address_book_outputs(address_book data);/*出力関数のプロトタイプ宣言*/

int main(void){
    
    int i,count,datasize;
    
    FILE *file;
    file=fopen("addressbook.csv", "w");
    fprintf(file,"名前,性別(1:男性　2:女性),年齢,生年月日,住所\n");
    
    address_book *data;
    
    datasize=10;
    data = (address_book*)malloc(sizeof(address_book) * datasize);
    
    count= 0;
    while(1){
        address_book_inputs(&data[count]);
        if (data[count].birthday==0)break; /*誕生日に０を入力すると終了*/
        
        count++;
        if (count>=datasize) {
            datasize += 10;
            data = (address_book*)reallocf(data, sizeof(address_book)*datasize);
        }
    }
    
    for(i=0;i<count;i++){
        address_book_outputs(data[i]);
        fprintf(file, "%s,%d,%d,%d,%s\n",data[i].name,data[i].gender,data[i].age,data[i].birthday,data[i].address);
        fclose(file);
    }
    
    free(data);
    
    return 0;
    
}

/*データを入力する*/
void address_book_inputs(address_book *data){
    printf("名前：");
    scanf("%s",data->name);/*名前を入力*/
    
    printf("性別(1:男性　2:女性)：");
    scanf("%d",&data->gender);
    
    printf("年齢：");
    scanf("%d",&data->age);
    
    printf("生年月日：");
    scanf("%d",&data->birthday);
    
    printf("住所；");
    scanf("%s",data->address);
}

/*入力したデータを出力する*/
void address_book_outputs(address_book data){
    
    printf("名前：%s\n",data.name);
    printf("性別(1:男性　2:女性)：%d\n",data.gender);
    printf("年齢：%d\n",data.age);
    printf("生年月日：%d\n",data.birthday);
    printf("住所：%s\n",data.address);
}
