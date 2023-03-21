#include<stdio.h>
#ifndef _CINEMA_H_
#define _CINEMA_H_
const int  MAX_MOVIE_NUM = 100;
const int  MAX_ROW_NUM = 5;
const int  MAX_HALL_NUM = 5;
const int  MAX_COL_NUM = 8;
#define MAX_TIKET  MAX_ROW_NUM * MAX_COL_NUM * MAX_HALL_NUM
#endif






typedef struct
{
	char name[20];
	char director[20];
	char actor[20];
	char introduction[100];
	int duration;

}Movie;
typedef struct
{
	char name[20];
	int line;
	int col;
	int ticke;
}Screening_hall;        

typedef struct
{
	char name[20];
	char password[20];
	int record;                             /*售票记录*/
}Audience;

typedef struct
{
	char user[20];
	char film[20];
	int screening_hall;
	int line;
	int column;
	
}Ticket_sales_record;
/*函数功能：初始化结构体
	
*/
void cinema_init();

/*
*函数功能：读取文件
* 参数 1：电影结构体
*/
int readFile(Movie* mov);

void saveFile(Movie* mov, int n);
void createFile(Movie* film);
void createFilm(Movie* film);
int readFile(Movie* mov);