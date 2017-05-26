#ifndef _NEWSTRUCTS_H
#define _NEWSTRUCTS_H



typedef struct FILEDESC
{
	char fileName[40];
	short fileSize;
	int fileMode;
	char owner[40];
	time_t creationTime;
	long indexOfNode;
} FILEDESC;

typedef struct INDEX_NODE
{
	short index[127];
} INDEX_NODE;

typedef struct FILE_DATA
{
	char data[254];
} FILE_DATA;

typedef union MEM_NODE
{
	struct FILEDESC fDescription;
	struct INDEX_NODE iNode;
	struct FILE_DATA fData;
} MEM_NODE;

typedef struct memdata
{
	short type;
	union MEM_NODE node;
} MEMDATA;

typedef struct INODE
{
	FILEDESC fileContent;
	long indexOfFile;
	struct INODE *next;
} INODE;

typedef struct directory
{
	struct INODE *hashTable[DIR_SIZE];
} DIRECTORY;


//should just have a pointer to FD node

typedef struct BITVECTOR
{
	unsigned char array[8192];
} BITVECTOR;

typedef struct SYSFILETABLE
{
	long fdIndex[DIR_SIZE];
	FILEDESC openFiles[DIR_SIZE];
	long numOpen;
	long dataIndex[DIR_SIZE];
	//maybe char fileNames[DIR_SIZE][40]; ?
	//POINTER TO FD? POINTER TO FD INFORMATION. COPY IT OVER
} SYSFILETABLE;

typedef struct PROCFILETABLE
{
 	int pid;
 	char fileNames[DIR_SIZE][40] ;
 	int canWrite[DIR_SIZE]; //WILL BE 1 FOR WRITE PRIVILEDGES
 	long numOpen;
} PROCFILETABLE;

#endif