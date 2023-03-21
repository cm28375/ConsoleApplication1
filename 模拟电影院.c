/*
* 电影院售票系统
* 主要包括：用户功能，管理员功能，菜单显示，主控模块
*
*
*/

#include <stdio.h>
#include<stdlib.h>
#include<cinema.h>


int movie_num = 0;

int main()
{
	int num_m;
	Movie *movie;
	scanf("%d", &num_m);
	readFilm(movie, num_m);

}





