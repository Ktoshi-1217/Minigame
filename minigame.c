/* TNC : MiniGame�쐬 */
/* Programed by Ktoshi */
/* 2020/10/22 �` 2021/01/14 */
#define TEST printf("�₠\n");

#define SWITCH_1 1
#define SWITCH_2 2
#define SWITCH_3 4
#define SWITCH_4 8

#define MAPX 30
#define MAPY 30

#define FILENAME "scoredata.DAT"
#define AMOUNT 20

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	<string.h>
#include	<ctype.h>
#include	<time.h>
#include	<conio.h>

typedef struct{
	int type;
	int x;
	int y;
	int savo;
	int hp;
	int attack;
}ENEMY;

typedef struct{
	int no;
	char name[10];
	char date[20];
	int score;
}DATA;

int gmap[MAPY][MAPX];

/*int�^�G���[�΍�**********************************************************************************/
int intscan(void)
{
int a;
char c[20];

	if(gets(c) == NULL)	return -2;
	if(!isdigit(c[0]))	return -1;
	a = atoi(c);

	return a;
}
/*map+���݂̃f�[�^�o��*****************************************************************************/
void mapdisplay(int hp,int mhp,int attack,int wave,int score,int flag)
{
int i,j;

	system("cls");
	printf("HP = %4d/%4d ATTACK = %2d%s WAVE:%3d SCORE:%8d\n",hp,mhp,attack,(flag)? "x2!":"   ",wave,score);
	for(i=0;i<MAPY;i++){
		for(j=0;j<MAPX;j++){
			switch(gmap[i][j]){
			case 0:
				printf("�� ");
				break;
			case 1:
				printf("�� ");
				break;
			case 2:
				printf("�� ");
				break;
			case 3:
				printf("�� ");
				break;
			case 4:
				printf("�� ");
				break;
			case 5:
				printf("�� ");
				break;
			case 6:
				printf("�� ");
				break;
			case 7:
				printf("�� ");
				break;
			case 8:
				printf("�� ");
				break;
			case 9:
				printf("�� ");
				break;
			default:
				printf("�H");
				break;
			}
		}
		printf("\n");
	}

}
/*�}�b�v�쐻***************************************************************************************/
void mapcreate(void)
{
int i,j;
int rsea,lsea,sima;

	for(i=0;i<MAPY;i++){
		lsea = abs(MAPX/2-i)+(rand()%3-1);
		rsea = abs(MAPX/2-i)+(rand()%3-1);
		sima = MAPX-(lsea+rsea);
		for(j=0;j<lsea;j++){
			gmap[i][j] = 1;
		}
		for(j;j<sima+lsea;j++){
			gmap[i][j] = 0;
		}
		for(j;j<MAPX;j++){
			gmap[i][j] = 1;
		}
	}

}
/*�ړ���̃`�F�b�N*********************************************************************************/
int move(int x,int y,char movd)
{

int ret = -1;

	switch(movd){

		case '2':	case 's':	case 'S':
			if(y < MAPY-1){
				switch(gmap[y+1][x]){
					case 0:	case 4:	case 5:	case 6:	case 7:
						ret = 2;
						break;
					case 9:
						ret = 10;
						break;
					default:
						ret = 0;
						break;
				}
			}else{
				ret = 0;
			}
			break;

		case '4':	case 'a':	case 'A':
			if(x > 0){
				switch(gmap[y][x-1]){
					case 0:	case 4:	case 5:	case 6:	case 7:
						ret = 4;
						break;
					case 9:
						ret = 10;
						break;
					default:
						ret = 0;
						break;
				}
			}else{
				ret = 0;
			}
			break;

		case '6':	case 'd':	case 'D':
			if(x < MAPX-1){
				switch(gmap[y][x+1]){
					case 0:	case 4:	case 5:	case 6:	case 7:
						ret = 6;
						break;
					case 9:
						ret = 10;
						break;
					default:
						ret = 0;
						break;
				}
			}else{
				ret = 0;
			}
			break;

		case '8':	case 'w':	case 'W':
			if(y > 0){
				switch(gmap[y-1][x]){
					case 0:	case 4:	case 5:	case 6:	case 7:
						ret = 8;
						break;
					case 9:
						ret = 10;
						break;
					default:
						ret = 0;
						break;
				}
			}else{
				ret = 0;
			}
			break;

		case '5':	case 'z':	case 'Z':	case' ':
			ret = 5;
			break;

		case 'p':	case 'P':	case 'e':	case 'E':
			ret = -2;
			break;

		case 3:
			puts("Debug End\n");
			exit(0);
			break;

		default:
			ret = -1;
			break;

	}

	return ret;

}
/*�U��*********************************************************************************************/
int attackmuki(int x,int y,char muki,int attack,ENEMY *enemy,int flag)
{
int i;
int ret=0;

	if(flag)	attack *= 2;

	for(i=0;i<4;i++){

		if(enemy->type){

			switch(muki){

				case '2':	case 's':	case 'S':
					if((x == enemy->x)&&(y+1 == enemy->y)){
						enemy->hp -= attack;
						if(enemy->hp < 0)	enemy->hp = 0;
						ret=1+i;
					}
					break;

				case '4':	case 'a':	case 'A':
					if((x-1 == enemy->x)&&(y == enemy->y)){
						enemy->hp -= attack;
						if(enemy->hp < 0)	enemy->hp = 0;
						ret=1+i;
					}
					break;

				case '6':	case 'd':	case 'D':
					if((x+1 == enemy->x)&&(y == enemy->y)){
						enemy->hp -= attack;
						if(enemy->hp < 0)	enemy->hp = 0;
						ret=1+i;
					}
					break;

				case '8':	case 'w':	case 'W':
					if((x == enemy->x)&&(y-1 == enemy->y)){
						enemy->hp -= attack;
						if(enemy->hp < 0)	enemy->hp = 0;
						ret=1+i;
					}
					break;

				case '0':	case'x':	case'X':
					ret = -1;
					break;

				default:
					printf("Input error\n");
					ret = -2;
					break;

			}

		}

		if(ret != 0)	break;
		enemy++;

	}

	return ret;
}
/*�G�̔���*****************************************************************************************/
void enemydrop(ENEMY *enemy,int wave)
{
int flag = 15;
int x,y;

	while(flag&SWITCH_1){
		x = MAPX/2-2+rand()%5;
		y = 2+rand()%5;
		if((gmap[y][x] == 0)||(gmap[y][x] == 4)||(gmap[y][x] == 5)||(gmap[y][x] == 6)||(gmap[y][x] == 7)){
			enemy->savo = gmap[y][x];
			if(wave%5!=0){
				enemy->type = 2;
				enemy->hp = wave;
				enemy->attack = sqrt(wave);
			}else if(wave % 50){
				enemy->type = 3;
				enemy->hp = wave*5;
				enemy->attack = sqrt(wave*5);
			}else{
				enemy->type = 8;
				enemy->hp = wave*20;
				enemy->attack = sqrt(wave*8);
			}
			gmap[y][x] = enemy->type;
			enemy->x = x;
			enemy->y = y;
			flag &= ~SWITCH_1;
		}
	}

	enemy++;

	while(flag&SWITCH_2){
		x = MAPX/2-2+rand()%5;
		y = MAPY-(2+rand()%5);
		if((gmap[y][x] == 0)||(gmap[y][x] == 4)||(gmap[y][x] == 5)||(gmap[y][x] == 6)||(gmap[y][x] == 7)){
			enemy->savo = gmap[y][x];
			gmap[y][x] = 2;
			enemy->type = 2;
			enemy->x = x;
			enemy->y = y;
			enemy->hp = wave;
			enemy->attack = sqrt(wave);
			flag &= ~SWITCH_2;
		}
	}

	enemy++;

	while(flag&SWITCH_3){
		x = 2+rand()%5;
		y = MAPY/2-2+rand()%5;
		if((gmap[y][x] == 0)||(gmap[y][x] == 4)||(gmap[y][x] == 5)||(gmap[y][x] == 6)||(gmap[y][x] == 7)){
			enemy->savo = gmap[y][x];
			gmap[y][x] = 2;
			enemy->type = 2;
			enemy->x = x;
			enemy->y = y;
			enemy->hp = wave;
			enemy->attack = sqrt(wave);
			flag &= ~SWITCH_3;
		}
	}

	enemy++;

	while(flag&SWITCH_4){
		x = MAPX-(2+rand()%5);
		y = MAPY/2-2+rand()%5;
		if((gmap[y][x] == 0)||(gmap[y][x] == 4)||(gmap[y][x] == 5)||(gmap[y][x] == 6)||(gmap[y][x] == 7)){
			enemy->savo = gmap[y][x];
			gmap[y][x] = 2;
			enemy->type = 2;
			enemy->x = x;
			enemy->y = y;
			enemy->hp = wave;
			enemy->attack = sqrt(wave);
			flag &= ~SWITCH_4;
		}
	}

}
/*�G�̈ړ�����*************************************************************************************/
char enemymove(int cx,int cy,int ex,int ey)
{
int x,y;
char ret;

	x = abs(cx-ex);
	y = abs(cy-ey);
	if(x<y){
		ret = 0;
	}else if(x>y){
		ret = 1;
	}else{
		ret = rand()%2;
	}

	if(ret){
		if(cx<ex)	ret = '4';
		else		ret = '6';
	}else{
		if(cy<ey)	ret = '8';
		else		ret = '2';
	}

	return ret;
}
/*�G�̃A�C�e���h���b�v*****************************************************************************/
void dropitem(ENEMY *enemy)
{
int kazu = rand()%100;

	if((enemy->type==3)||(enemy->type==8)){
		gmap[enemy->y][enemy->x] = 7;
	}else if(kazu < 20){
		gmap[enemy->y][enemy->x] = 4;
	}else if(kazu < 35){
		gmap[enemy->y][enemy->x] = 5;
	}else if(kazu < 55){
		gmap[enemy->y][enemy->x] = 6;
	}else{
		gmap[enemy->y][enemy->x] = enemy->savo;
	}

}
/*�A�C�e���l����***********************************************************************************/
void getitem(int x,int y,int *hp,int *mhp,int *attack,int *flag,int *score ,float scoremag)
{

	if(gmap[y][x] == 4){
		*mhp += 1;
		*hp += *mhp/20;
		if(*mhp<*hp)	*hp = *mhp;
		*score += 10*scoremag;
	}else if(gmap[y][x] == 5){
		*attack += 1;
		*score += 10*scoremag;
	}else if(gmap[y][x] == 6){
		*flag |= SWITCH_2;
		*score += 10*scoremag;
	}else if(gmap[y][x] == 7){
		*mhp += 5;
		*hp += *mhp/8;
		if(*mhp<*hp)	*hp = *mhp;
		*attack += 3;
		*score += 50*scoremag;
	}

}
/**************************************************************************************************/
/**************/
/*  �퓬����  */
/**************/
int submain(void)
{
int i,j;
int cx,cy;
int csavo,cmove;
char cmovd;
int ret;
int maxhp = 100;
int chp = maxhp;
int cattack = 5;
int wave = 0;
int flag = 0;
int enemykazu = 0;
int emove;
char emovd;
int score = 0;
float scoremag = 0.9;
char yesno;
ENEMY enemy[4];

	/* �^���������� */
	srand((unsigned)time(NULL));

	/* �}�b�v���� */
	mapcreate();

	/* �v���C���[�z�u */
	cx = MAPX/2;
	cy = MAPY/2;
	csavo = gmap[cy][cx];
	gmap[cy][cx] = 9;

	/* �}�b�v�\�� */
	mapdisplay(chp,maxhp,cattack,wave,score,flag & SWITCH_2);

	do{

		/* �v���C���[ */
		printf("\n=>");
		cmovd = getch();
		printf("%c\n",cmovd);
		cmove = move(cx,cy,cmovd);

		switch(cmove){
			case 2:
				gmap[cy][cx] = csavo;
				cy += 1;
				getitem(cx,cy,&chp,&maxhp,&cattack,&flag,&score,scoremag);
				csavo = 0;
				gmap[cy][cx] = 9;
				break;

			case 4:
				gmap[cy][cx] = csavo;
				cx -= 1;
				getitem(cx,cy,&chp,&maxhp,&cattack,&flag,&score,scoremag);
				csavo = 0;
				gmap[cy][cx] = 9;
				break;

			case 6:
				gmap[cy][cx] = csavo;
				cx += 1;
				getitem(cx,cy,&chp,&maxhp,&cattack,&flag,&score,scoremag);
				csavo = 0;
				gmap[cy][cx] = 9;
				break;

			case 8:
				gmap[cy][cx] = csavo;
				cy -= 1;
				getitem(cx,cy,&chp,&maxhp,&cattack,&flag,&score,scoremag);
				csavo = 0;
				gmap[cy][cx] = 9;
				break;

			case 5:
				printf("�ǂ���ɍU�����܂����H�i0��X�Ŗ߂�j\n");
				do{
					printf("=>");
					cmovd = getch();
					printf("%c\n",cmovd);
					ret = attackmuki(cx,cy,cmovd,cattack,enemy,flag & SWITCH_2);
				}while(ret==-2);

				if(ret == -1){
					mapdisplay(chp,maxhp,cattack,wave,score,flag & SWITCH_2);
					if(wave != 0){
						for(i=0;i<4;i++){
							printf("%d�̖� �̗�:%d �U����:%d\n",i+1,enemy[i].hp,enemy[i].attack);
						}
					}
					continue;
				}

				if(ret!=0){
					flag &= ~SWITCH_2;
					if(enemy[ret-1].hp <= 0){
						dropitem(&enemy[ret-1]);
						if(enemy[ret-1].type == 2){
							score += 100*scoremag;
						}else if(enemy[ret-1].type == 3){
							score += 2000*scoremag;
						}else{
							score += 10000*scoremag;
						}
						enemy[ret-1].type = 0;
						enemykazu -= 1;
					}
				}

				break;

			case 0:
				printf("�ړ��ł��܂���\n");
				continue;

			case -1:
				printf("Input error\n");
				continue;

			case -2:
				while(1){
					printf("�{���ɂ�߂܂����H(Y or N)\n=>");
					yesno = getch();
					if((yesno == 'y')||(yesno == 'Y')){
						score = 0;
						break;
					}else if((yesno == 'n')||(yesno == 'N')){
						cmove = -1;
						break;
					}
					printf("Input error\n");
				}
				if((yesno == 'n')||(yesno == 'N')){
					mapdisplay(chp,maxhp,cattack,wave,score,flag & SWITCH_2);
					if(wave != 0){
						for(i=0;i<4;i++){
							printf("%d�̖� �̗�:%d �U����:%d\n",i+1,enemy[i].hp,enemy[i].attack);
						}
					}
				}
				continue;

		}

		/* �G */
		if(enemykazu){
			for(i=0;i<4;i++){
				if(enemy[i].type){
					emovd = enemymove(cx , cy , enemy[i].x , enemy[i].y);
					emove = move(enemy[i].x , enemy[i].y , emovd);
					switch(emove){
						case 2:
							gmap[enemy[i].y][enemy[i].x] = enemy[i].savo;
							enemy[i].y += 1;
							enemy[i].savo = gmap[enemy[i].y][enemy[i].x];
							gmap[enemy[i].y][enemy[i].x] = enemy[i].type;
							break;

						case 4:
							gmap[enemy[i].y][enemy[i].x] = enemy[i].savo;
							enemy[i].x -= 1;
							enemy[i].savo = gmap[enemy[i].y][enemy[i].x];
							gmap[enemy[i].y][enemy[i].x] = enemy[i].type;
							break;

						case 6:
							gmap[enemy[i].y][enemy[i].x] = enemy[i].savo;
							enemy[i].x += 1;
							enemy[i].savo = gmap[enemy[i].y][enemy[i].x];
							gmap[enemy[i].y][enemy[i].x] = enemy[i].type;
							break;

						case 8:
							gmap[enemy[i].y][enemy[i].x] = enemy[i].savo;
							enemy[i].y -= 1;
							enemy[i].savo = gmap[enemy[i].y][enemy[i].x];
							gmap[enemy[i].y][enemy[i].x] = enemy[i].type;
							break;

						case 10:
							chp -= enemy[i].attack;
							if(chp<0)	chp=0;
							break;
					}
				}
			}
		}else{
			if(flag & SWITCH_1)	flag &= ~(SWITCH_1);
			else{
				flag |= SWITCH_1;
				scoremag += 0.1;
				wave++;
				enemydrop(enemy,wave);
				enemykazu = 4;
			}
		}

		/* �J���X�g */
		if(score > 99999999)	score=99999999;

		/* �}�b�v�\�� */
		mapdisplay(chp,maxhp,cattack,wave,score,flag & SWITCH_2);

		/* �G��� */
		for(i=0;i<4;i++){
			printf("%d�̖� �̗�:%d �U����:%d\n",i+1,enemy[i].hp,enemy[i].attack);
		}

		/* ���S���� */
		if(chp <= 0){
			printf("\nGAME OVER\n");
			break;
		}

	}while(cmove != -2);

	//system("pause");
	return score;
}

/*�t�@�C������ǂݍ���******************************************************************************/
void reeddata(DATA *data)
{
int i;
char temporary[20] = {" "};
FILE *fp;

	if((fp = fopen(FILENAME,"r")) != NULL){

		for(i=0;i<AMOUNT;i++){
			if((fscanf(fp,"%d %s %s" , &data->no , data->name , data->date) == EOF)||(fscanf(fp,"%s %d",&temporary[1] , &data->score) == EOF)){
				data->no = 0;
				break;
			}
			strcat(data->date,temporary);
			data++;
		}
		fclose(fp);

	}else{
		data->no = 0;
		data->score = 0;
	}

}
/*�f�[�^�\��***************************************************************************************/
void datadis(DATA *data)
{
int i;

	printf("-------------------------------------------------------------------------------\n");
	printf("�X�R�A�f�[�^\n");
	printf("No.   NAME    DATE              SCORE\n");
	for(i=0;(data->no != 0)&&(i<AMOUNT);i++){
		printf("%2d  %-8s  %16s  %8d\n" , data->no , data->name , data->date , data->score);
		data++;
	}
	for(i;i<AMOUNT;i++){
		printf(" 0  ________  0000/00/00 00:00         0\n");
	}
	printf("-------------------------------------------------------------------------------\n");

}
/*�f�[�^�ǉ�***************************************************************************************/
void adddata(DATA *data,int score)
{
int i;
int conditions;
DATA newdata;
DATA savedata;
time_t t;
struct tm *lt;

	printf("[Ctrl + Z]�ŃZ�[�u�����I���܂�\n");
	conditions = 1;
	do{
		printf("  NAME\n");
		printf("________\r");
		if(gets(newdata.name) == NULL)	return;
		if(isdigit(newdata.name[0]))	printf("���O�̍ŏ��ɐ����͂����܂���\n");
		else if(strlen(newdata.name) > 8)	printf("���O���������܂�\n");
		else{
			conditions = 0;
			for(i=0;((data+i)->no!=0)&&(i<AMOUNT);i++){
				if(!strcmp((data+i)->name,newdata.name)){
					printf("�������O�͕t�����܂���\n");
					conditions = 1;
					break;
				}
			}
		}
	}while(conditions);

	newdata.score = score;

	t = time(NULL);
	lt = localtime(&t);
	sprintf(newdata.date,"%04d/%02d/%02d %02d:%02d",
		lt->tm_year+1900,
		lt->tm_mon + 1,
		lt->tm_mday,
		lt->tm_hour,
		lt->tm_min
	);

	for(i=0;(data->score > newdata.score)&&(data->no!=0)&&(i<AMOUNT);i++)	data++;

	for(i;i<AMOUNT;i++){
		if(data->no==0){
			if(i == 0){
				newdata.no = 1;
				*data = newdata;
				break;
			}
			newdata.no = (data-1)->no +1;
			*data = newdata;
			break;
		}
		savedata = *data;
		newdata.no = savedata.no;
		*data = newdata;

		newdata = savedata;
		data++;
	}
	if(i<AMOUNT)	(data+1) -> no = 0;

}
/*�f�[�^�̍폜*************************************************************************************/
void deldata(DATA *data)
{
int yesno=1;
int no;
int i;
char name[10];

	if(!data->no){
		printf("error\n");
		return;
	}

	printf("[Ctrl + Z]�Ŗ߂�܂�\n");
	do{
		no = 0;
		printf("�ǂ̃f�[�^�������܂����H(�i���o�[�����O����͂��Ă�������)\n");
		printf("________\r");
		if(gets(name) == NULL)	return;
		if(isdigit(name[0])){
			for(i=0;((data+i)->no!=0)&&(i<AMOUNT);i++);
			if((atoi(name) > 0)&&(atoi(name) <= i))	no = atoi(name);
		}else{
			for(i=0;((data+i)->no!=0)&&(i<AMOUNT);i++){
				if(!strcmp((data+i)->name,name)){
					no = i+1;
					break;
				}
			}
		}

		if(no){
			no--;
			printf("\n%2d  %-8s  %16s  %8d\n" , (data+no)->no , (data+no)->name , (data+no)->date , (data+no)->score);
			printf("���̃f�[�^��{���ɏ����܂����H\n");
			printf("�͂�=>0 ������=>1\n");
			yesno = intscan();
		}else	printf("Error\n\n");

	}while(yesno);

	data+=no;

	for(no;((data+1)->no!=0)&&(no<AMOUNT);no++){
		*data = *(data+1);
		data->no -= 1;
		data++;
	}

	data->no = 0;

	printf("\n�ύX���������܂����I\n");

}
/*�S�f�[�^�폜*************************************************************************************/
void alldelfile(DATA *data)
{

	printf("\n�S�Ẵf�[�^�������܂����H\n");
	printf("�͂�=>0\n");
	if(intscan())	return;
	printf("�{���ɏ����܂����H\n");
	printf("�͂�=>0\n");
	if(intscan())	return;
	printf("������܂���ˁH\n");
	printf("�͂�=>0\n");
	if(intscan())	return;

	data->no = 0;

	printf("\n�ύX���������܂���\n");

}
/*�t�@�C���̃Z�[�u*********************************************************************************/
int filesave(DATA *data)
{
int i;
int err=0;
int success = 1;
FILE *fp;

	if((fp = fopen(FILENAME,"w")) != NULL){

		for(i=0;(data->no != 0)&&(i<AMOUNT)&&(success == 1);i++){
			if(fprintf(fp,"%d %s %s %d\n",data->no , data->name , data->date , data->score) == 0){
				printf("�Z�[�u�Ɏ��s���܂���\n\n");
				printf("�ǂ����܂����H\n0=>���̂܂܏I��� 1=>�߂�\n");
				err = intscan();
				success = 0;
				break;
			}
			data++;
		}
		fclose(fp);

	}else{
		printf("�t�@�C���̍쐬�Ɏ��s���܂����H\n\n");
		printf("�ǂ����܂����H\n0=>���̂܂܏I��� 1=>�߂�\n");
		err = intscan();
		success = 0;
	}

	if(success)	printf("�t�@�C���ւ̃Z�[�u���������܂����I\n");

	return err;

}
/***************************************************************************************************/
/**************/
/*  file����  */
/**************/

void filemain(void)
{

int err=0;
int select;
int change = 0;
DATA data[AMOUNT];

	/* �ǂݍ��ݕ� */
	reeddata(data);

	do{

		do{

			/* �X�R�A�\�� */
			datadis(data);

			/* �I�� */
			printf("�ǂ����܂���?\n");
			printf("1=>�f�[�^������ 2=>���ׂẴf�[�^������ 0=>�Z�[�u���Ė߂� 9=>�Z�[�u�����ɖ߂�\n");
			select = intscan();

			/* ���� */
			switch(select){
				case 0:	break;
				case 1:	deldata(data);		change = 1;	break;
				case 2:	alldelfile(data);	change = 1;	break;
				case 9:	select = 0;	change *= 2;	break;
				default:	puts("Error");	break;
			}
			printf("\n");

		}while(select);

		/* �t�@�C���ۑ� */
		if(change == 2){
			printf("�{���ɃZ�[�u�����ɖ߂�܂����H?\n");
			printf("�͂�=>0 ������=>1\n");
			err = intscan();
			change = 1;
		}else if(change)	err = filesave(data);

	}while(err);

}
/***************************************************************************************************/
/**************/
/*  main����  */
/**************/
int main(void){

int title[10][15] = {	{ 1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1 } ,
						{ 1,0,0,0,0,0,0,0,0,0,0 ,0,0,0,1 } ,
						{ 1,0,0,0,0,0,0,0,0,0,0 ,0,0,0,1 } ,
						{ 1,0,0,2,0,3,0,4,0,5,0 ,0,0,0,1 } ,
						{ 1,0,0,0,0,0,0,0,0,0,0 ,0,0,0,1 } ,
						{ 1,0,0,0,0,0,0,0,8,9,10,6,7,0,1 } ,
						{ 1,0,0,0,0,0,0,0,0,0,0 ,0,0,0,1 } ,
						{ 1,1,1,1,1,1,1,1,1,1,1 ,1,1,1,1 }	};
int x = 15;
int y = 10;

int i,j;
char select;
char ca;

int score;
DATA data[AMOUNT];

	do{

		system("cls");
		for (i=0;i<y;i++){
			for(j=0;j<x;j++){
				switch(title[i][j]){
				case 0:
					printf("  ");
					break;
				case 1:
					printf("�� ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("�R");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("K ");
					break;
				case 7:
					printf("T ");
					break;
				case 8:
					printf("�i");
					break;
				case 9:
					printf("��");
					break;
				case 10:
					printf("�j");
					break;
				}
			}
			printf("\n");
		}

		printf("1=>�Q�[���X�^�[�g�I 2=>����܂ł̋L�^ 3=>�I��\n=>");
		select = getch();
		printf("%c\n",select);

		switch(select){
			case '1':
				system("cls");
				puts("�Q�[������\n");
				puts("�Q�[���V�X�e�� �F WAVE��");
				puts("�X�e�[�W �F �Ђ��`�̌Ǔ�");
				puts("������@ �F ��{����̓e���L�[���g�p���܂��B");
				puts("���ł����APC�ł̊�{�Ƃ��āA'W'�A'A'�A'S'�A'D'���g����悤�ɂȂ��Ă��܂��B\n");
				puts("�����L�[�����F        �i��)");
				puts("                        �v                                ������ړ��F�v�L�[�A8�L�[");
				puts("                        �W");
				puts("              �i���j�`�S�� �U�c�i���j            �������ړ��F�`�L�[�A4�L�[  �E�����ړ��F�c�L�[�A6�L�[");
				puts("                        �Q");
				puts("                        �r                                �������ړ��F�r�L�[�A2�L�[");
				puts("                      �i���j\n\n");
				puts("�U�����@�F�U����'5'��'Z'�ōs����B");
				puts("���܂��A�X�y�[�X�L�[�ł��U�����[�h�ɐ؂�ւ��邱�Ƃ��ł���B");
				puts("          �U�����[�h�ɐ؂�ւ���ƁA�U���̕����𕷂����̂ŁA�����L�[����́B");
				puts("          �U�������ɓG�����Ȃ��Ƃ��A�U���͎��s����A�^�[�����i�݂܂��B\n");
				puts("'E'�܂���'P'�ŃQ�[�����I���ł��܂��B�i�������L�^�͕ۑ�����܂���j\n");
				puts("�A�C�R�������F���̃Q�[����8�̃A�C�R�����g�p���Ă��܂��B");
				puts("              �v���C���[�L�����N�^�[�F��");
				puts("              �C�i�N���s�j�F��");
				puts("              �G�L�����N�^�[ : ��");
				puts("              �{�X�L�����N�^�[ �F ��");
				puts("              �̗̓A�b�v�A�C�e�� �F ��");
				puts("              �U���̓A�b�v�A�C�e�� �F ��");
				puts("              �`���[�W�U���A�C�e�� �F ��");
				puts("              �S�X�e�[�^�X����A�C�e�� �F ��\n\n");

				puts("�p������ɂ�Enter�������Ă������B");
				puts("�߂�Ȃ��Back Space�������Ă��������B\n\n\n\n");
				puts("���ӁF��ʃT�C�Y�͐������炱�̕��܂ł��S��������x���D�܂����ł��B");
				ca = '\0';
				while((ca != '\r')&&(ca != '\b'))	ca = getch();
				if(ca == '\r'){
					score = submain();

					if(score>0){
						reeddata(data);
						adddata(data,score);
						filesave(data);
					}
				}

				break;

			case '2':
				filemain();
				break;

			case '3':	break;

			case 3:
				puts("Debug End\n");
				exit(0);
				break;

			default:
				puts("Input Error\n");
				break;

		}

	}while(select != '3');

	return 0;
}
