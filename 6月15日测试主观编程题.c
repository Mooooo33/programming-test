// 题目内容：输入5个学生3门课程的数据信息，定义一个结构体类型，成员信息包括学生学号（整型），学生姓名（字符型，长度不超过20）和3门课程成绩（浮点型）；定义四个功能函数，分别为输入函数input()，输出函数output()，sort()排序函数（按姓名从小到大的顺序排序并输出，tongji()统计函数（计算每个同学三门课程的总分，输出总分最高的同学信息和总分）。

// 输入格式:
// 学号1 （回车）
// 姓名1 （回车）
// 学号1的课程1成绩 （回车）
// 学号1的课程2成绩（回车）
// 学号1的课程3成绩（回车）
// 学号2（回车）
// 姓名2 （回车）
// 学号2课程1成绩 （回车）
// 学号2课程2成绩（回车）
// 学号2课程3成绩（回车）
// .........

// 输出格式：
// 学号 姓名 三门课程成绩（排序后的信息，每个同学的信息一行；每个成员与成员之间用空格隔开；每们课成绩小数点后保留两位小数；每行最后一门课程的成绩后面也要保留一个空格）
// 学号 姓名 总分（总分小数点后保留两位小数，总分后面也要保留一个空格）

// 输入样例：
// 1
// student
// 87
// 98
// 68
// 2
// apple
// 87
// 95
// 84
// 3
// orange
// 69
// 78
// 98
// 4
// puple
// 98
// 85
// 69
// 5
// windows
// 96
// 95
// 45

// 输出样例：
// 2 apple 87.00 95.00 84.00 
// 3 orange 69.00 78.00 98.00 
// 4 puple 98.00 85.00 69.00 
// 1 student 87.00 98.00 68.00 
// 5 windows 96.00 95.00 45.00 
// 2 apple 266.00

#include <stdio.h>
#include <string.h>
#define LEN 21
#define NUM 5
#define SCO 3
struct Student
{
    int num;
    char name[LEN];
    float score[SCO];
} date[NUM], * p = date;

int input(struct Student date[]);
int output(struct Student date[]);
int sort(struct Student date[]);
int tongji(struct Student date[]);

int main(void)
{
    input(p);
    sort(p);
    output(p);
    tongji(p);

    return 0;
}

int input(struct Student date[])
{
    for (int i = 0; i < NUM; i++)
        scanf("%d %s %f %f %f", &date[i].num, &date[i].name, &date[i].score[0]
                              , &date[i].score[1], &date[i].score[2]);

    return 0;
}

int sort(struct Student date[])
{
    struct Student temp;

	for(int i = 0; i < NUM - 1; i++)
	{
		for(int j = 0; j < NUM - 1 - i; j++)
		{
			if(strcmp(date[j].name, date[j + 1].name) > 0)
			{
				temp = date[j + 1];
				date[j + 1] = date[j];
				date[j] = temp;
			}
		}
	}

    return 0;
}

int output(struct Student date[])
{
    for (int i = 0; i < NUM; i++)
        printf("%d %s %.2f %.2f %.2f \n", date[i].num, date[i].name, date[i].score[0]
                                        , date[i].score[1], date[i].score[2]);
    
    return 0;
}

int tongji(struct Student date[])
{
    struct Student temp;
    float sum[NUM], max;
    int cnt;

	for(int i = 0; i < NUM - 1 ;i++)
	{
		for(int j = 0; j < NUM - 1 - i; j++)
		{
			if(date[j].num > date[j + 1].num)
			{
				temp = date[j + 1];
				date[j + 1] = date[j];
				date[j] = temp;
			}
		}
	}
    
    for (int i = 0; i < NUM; i++)
        sum[i] = date[i].score[0] + date[i].score[1] + date[i].score[2];

    max = sum[0];

    for (int i = 1; i < NUM; i++)
    {
        if (max < sum[i])
        {  
            max = sum[i];
            cnt = i;
        }
    }

    printf("%d %s %.2f ", date[cnt].num, date[cnt].name, max);

    return 0;
}
