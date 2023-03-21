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
	if ((fp = fopen("movie_list.txt", "w")) == NULL)  /*��д��ʽ��ָ���ļ�*/
	{
		printf("Erorr:can not open file !\n");/*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                        /*Ȼ���˳�*/
	}
	fwrite(mov, sizeof(Movie), n, fp);          /*һ�������ļ�д��n����¼*/
	fclose(fp);                        /*�ر��ļ�*/
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
	fread(&mov[i], sizeof(Movie), 1, fp);      /*������һ����¼*/
	while (!feof(fp))                  /*�ļ�δ����ʱѭ��*/
	{
		i++;
		fread(&mov[i], sizeof(Movie), 1, fp);  /*�ٶ�����һ����¼*/
	}
	fclose(fp);
	return i;                        /*���ؼ�¼����*/
}



