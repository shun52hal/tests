
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PARSONS 2

typedef struct{
    char name[200];
    char gender[100];
    int age;
    int birthday;
    char address[1000];
    
} address_book;

void address_book_inputs(address_book *data);/*入力関数のプロトタイプ宣言*/
void address_book_outputs(address_book data);/*出力関数のプロトタイプ宣言*/

int main(void)
{
    address_book data[2];
    int i;
    
    FILE *file;
    file=fopen("addressbook.csv", "w");
    fprintf(file,"名前,性別,年齢,生年月日,住所\n");
    
    
    for (i=0; i<PARSONS; i++) {
        address_book_inputs(&data[i]);
    }
    
    for (i=0; i<PARSONS; i++) {
        address_book_outputs(data[i]);
        fprintf(file, "%s,%s,%d,%d,%s\n",data[i].name,data[i].gender,data[i].age,data[i].birthday,data[i].address);
    }
    fclose(file);
}

/*データを入力する*/
void address_book_inputs(address_book *data){
    printf("名前：");
    scanf("%s",data->name);/*名前を入力*/
    
    printf("性別(1:男性　2:女性)：");
    scanf("%s",data->gender);
    
    printf("年齢：");
    scanf("%d",&data->age);
    
    printf("生年月日：");
    scanf("%d",&data->birthday);
    
    printf("住所；");
    scanf("%s",data->address);
}

/*入力したデータを出力する*/
void address_book_outputs(address_book data){
    
    printf("名前,性別,年齢,生年月日,住所\n");
    printf("%s,%s,%d,%d,%s\n",data.name,data.gender,data.age,data.birthday,data.address);
}
