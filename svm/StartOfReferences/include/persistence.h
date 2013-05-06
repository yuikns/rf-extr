#ifndef __PERSISTENCE_H__
#define __PERSISTENCE_H__

#ifndef CALLBACK_LEN
#define CALLBACK_LEN 9
//#define CALLBACK_LEN 6
#endif // CALLBACK_LEN

typedef struct sFeatureData
{
	int qid;
	//char fileName[1024];	
	int t[5];
	int positive;
	int offset;
	int adjacencyOffset[2]; //0: prev 1:next 
	int fid[CALLBACK_LEN][2];//feature info data fid[x][0] == beforeData fid[x][1] == totalData
	//fid means all collected key words before && total of the offset
	int seq[CALLBACK_LEN][4];
	//CALLBACK_LEN :functions 
	//4:0)all 1)prev&&next 2)words 3)seq of vari
	double density[CALLBACK_LEN][3][2];//6:method 3: all prev&next(kwd) prev&next(100*words)  2: prev next
	double vari[2];
} featureData;



typedef struct
{
	int top;
	featureData data[200];
} featureDataContainer;


//init
int dbInit(void);
int doCreateTable(void);


//int doGetFeatureData(void *a_param, int argc, char **argv, char **column);
//int doGetFeatureDataInfo(void *a_param, int argc, char **argv, char **column);

int insertFeatureInfo(const char *fileName,int num);
int insertFeature(const char* fileName,featureData data);
int cleanFeature(const char* fileName);
int getFeature(const char *fileName,featureDataContainer *data);

char *queryEscape(const char *str);

#endif // __PERSISTENCE_H__
