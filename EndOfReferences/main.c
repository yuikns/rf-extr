#include "hftctl.h"
#include "eftctl.h"
#include "hftnpse.h"
#include "dirTraversal.h"
#include "persistence.h"
#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define POFI(x) insertFilterData(1,x,strlen(x))
#define DEFI(x) insertFilterData(0,x,strlen(x))

int genSamples4Endness()
{
	dbInit();
	initFilterData();
	/*
	//filters (before)
	// APPENDIX
	// AUTHOR BIOGRAPHY(IES)
	// ACKNOWLEDGEMENT
	// TABLES
	insertFilterData(1,"REFERENCES AND BIBLIOGRAPHY",strlen("REFERENCES AND BIBLIOGRAPHY"));
	insertFilterData(1,"REFERENCES",strlen("REFERENCES"));
	insertFilterData(0,"CONFERENCES",strlen("CONFERENCES"));
	insertFilterData(1,"BIBLIOGRAPHY",strlen("BIBLIOGRAPHY"));
	insertFilterData(1,"BIBLIOGRAPHIES",strlen("BIBLIOGRAPHIES"));
	insertFilterData(0,"AUTHOR BIOGRAPHY",strlen("AUTHOR BIOGRAPHY"));
	insertFilterData(0,"AUTHOR BIOGRAPHIES",strlen("AUTHOR BIOGRAPHIES"));
	*/
	POFI("APPENDIX");
	POFI("TABLE");
	POFI("ACKNOWLEDGEMENT");
	POFI("AUTHOR BIBLIOGRAPHIES");
	POFI("AUTHOR BIBLIOGRAPHY");
	
	//DEFI()
	
	
	setTrainFile(fopen("train.txt","w")); // train.txt
	setTestFile(fopen("test.txt","w")); // test.txt     
	srand((unsigned int)time(NULL));
	if(getTrainFile() == NULL || getTestFile() == NULL)
	{
		fprintf(stderr,"error opening sample file\n");
		return -1;
	}
	
	//dir traversal,and  author to ctl
	dirTraversal("data/",1,genEndSampleCtl);
	
	cleanFilterData();
	fclose(getTrainFile());
	fclose(getTestFile());	
	
	return getFileNum();
}


int main(int argc,char *argv[])
{
	int fileNum = 0;
	
	
	
	fileNum = genSamples4Endness();
	printf("done \n total : %d\n",fileNum);
	return 0;
}

