#include<cinema.h>


void cinema_init()
{

	Movie movie = { "0", "0", "0", "0", 0 };

	Screening_hall hall = { "0", MAX_ROW_NUM, MAX_COL_NUM, MAX_COL_NUM * MAX_ROW_NUM };

	Audience audience = { "0", "0", 0 };

	Ticket_sales_record record = { "0", "0", MAX_HALL_NUM, MAX_ROW_NUM, MAX_COL_NUM };

}
void createFilm(Movie* film)
{
	FILE* fp;
	int n;
	if ((fp = fopen("movies_list.txt", "w")) == NULL)
	{
		printf("Error:can not open file");
		exit(0);
	}
	printf("Input movie \' information:\n");
	n = readFilm(film, movie_num);
	fwrite(film, sizeof(Movie), n, fp);
	fclose(fp);
	return n;
}
int readFilm(Movie* film, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("Input one movie \'s information\n");
		printf("Name:      \n");
		scanf("%s", &film[i].name);
		printf("Director:      \n");
		scanf("%s", &film[i].director);
		printf("actor:      ");
		scanf("%s", &film[i].actor);
		printf("introduction:      ");
		scanf("%s", &film[i].introduction);
		printf("duration:      ");
		scanf("%d", &film[i].duration);
		return 0;
	}
}

void saveFile(Movie* mov, int n)
{
	FILE* fp;
	if ((fp = fopen("movie_list.txt", "w")) == NULL)  /*以写方式打开指定文件*/
	{
		printf("Erorr:can not open file !\n");/*若打开失败，输出提示信息*/
		exit(0);                        /*然后退出*/
	}
	fwrite(mov, sizeof(Movie), n, fp);          /*一次性向文件写入n条记录*/
	fclose(fp);                        /*关闭文件*/
}
int readFile(Movie* mov)
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("movie_list.txt", "r")) == NULL)
	{
		printf("File does not exist,create it first:\n");
		return 0;
	}
	fread(&mov[i], sizeof(Movie), 1, fp);      /*读出第一条记录*/
	while (!feof(fp))                  /*文件未结束时循环*/
	{
		i++;
		fread(&mov[i], sizeof(Movie), 1, fp);  /*再读出下一条记录*/
	}
	fclose(fp);
	return i;                        /*返回记录条数*/
}



