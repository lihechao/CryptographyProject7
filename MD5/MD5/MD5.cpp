// MD5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MD5.h"
void HMD5(MD_Buffer *buf,WORD X[BLOCK_WORD_SIZE])	/*MD5压缩函数*/
{
	WORD A=buf->A,B=buf->B,C=buf->C,D=buf->D;	/*保存寄存器初始值*/
	RFF(A,B,C,D,X[0], 7,0xd76aa478);
	RFF(D,A,B,C,X[1],12,0xe8c7b756);
	RFF(C,D,A,B,X[2],17,0x242070db);
	RFF(B,C,D,A,X[3],22,0xc1bdceee);
	RFF(A,B,C,D,X[4], 7,0xf57c0faf);
	RFF(D,A,B,C,X[5],12,0x4787c62a);
	RFF(C,D,A,B,X[6],17,0xa8304613);
	RFF(B,C,D,A,X[7],22,0xfd469501);
	RFF(A,B,C,D,X[8], 7,0x698098d8);
	RFF(D,A,B,C,X[9],12,0x8b44f7af);
	RFF(C,D,A,B,X[10],17,0xffff5bb1);
	RFF(B,C,D,A,X[11],22,0x895cd7be);
	RFF(A,B,C,D,X[12], 7,0x6b901122);
	RFF(D,A,B,C,X[13],12,0xfd987193);
	RFF(C,D,A,B,X[14],17,0xa679438e);
	RFF(B,C,D,A,X[15],22,0x49b40821);
	
	RFG(A,B,C,D,X[1], 5,0xf61e2562);
	RFG(D,A,B,C,X[6], 9,0xc040b340);
	RFG(C,D,A,B,X[11],14,0x265e5a51);
	RFG(B,C,D,A,X[0],20,0xe9b6c7aa);
	RFG(A,B,C,D,X[5], 5,0xd62f105d);
	RFG(D,A,B,C,X[10], 9,0x02441453);
	RFG(C,D,A,B,X[15],14,0xd8a1e681);
	RFG(B,C,D,A,X[4],20,0xe7d3fbc8);
	RFG(A,B,C,D,X[9], 5,0x21e1cde6);
	RFG(D,A,B,C,X[14], 9,0xc33707d6);
	RFG(C,D,A,B,X[3],14,0xf4d50d87);
	RFG(B,C,D,A,X[8],20,0x455a14ed);
	RFG(A,B,C,D,X[13], 5,0xa9e3e905);
	RFG(D,A,B,C,X[2], 9,0xfcefa3f8);
	RFG(C,D,A,B,X[7],14,0x676f02d9);
	RFG(B,C,D,A,X[12],20,0x8d2a4c8a);
	
	RFH(A,B,C,D,X[5], 4,0xfffa3942);
	RFH(D,A,B,C,X[8],11,0x8771f681);
	RFH(C,D,A,B,X[11],16,0x6d9d6122);
	RFH(B,C,D,A,X[14],23,0xfde5380c);
	RFH(A,B,C,D,X[1], 4,0xa4beea44);
	RFH(D,A,B,C,X[4],11,0x4bdecfa9);
	RFH(C,D,A,B,X[7],16,0xf6bb4b60);
	RFH(B,C,D,A,X[10],23,0xbebfbc70);
	RFH(A,B,C,D,X[13], 4,0x289b7ec6);
	RFH(D,A,B,C,X[0],11,0xeaa127fa);
	RFH(C,D,A,B,X[3],16,0xd4ef3085);
	RFH(B,C,D,A,X[6],23,0x04881d05);
	RFH(A,B,C,D,X[9], 4,0xd9d4d039);
	RFH(D,A,B,C,X[12],11,0xe6db99e5);
	RFH(C,D,A,B,X[15],16,0x1fa27cf8);
	RFH(B,C,D,A,X[2],23,0xc4ac5665);
	
	RFI(A,B,C,D,X[0], 6,0xf4292244);
	RFI(D,A,B,C,X[7],10,0x432aff97);
	RFI(C,D,A,B,X[14],15,0xab9423a7);
	RFI(B,C,D,A,X[5],21,0xfc93a039);
	RFI(A,B,C,D,X[12], 6,0x655b59c3);
	RFI(D,A,B,C,X[3],10,0x8f0ccc92);
	RFI(C,D,A,B,X[10],15,0xffeff47d);
	RFI(B,C,D,A,X[1],21,0x85845dd1);
	RFI(A,B,C,D,X[8], 6,0x6fa87e4f);
	RFI(D,A,B,C,X[15],10,0xfe2ce6e0);
	RFI(C,D,A,B,X[6],15,0xa3014314);
	RFI(B,C,D,A,X[13],21,0x4e0811a1);
	RFI(A,B,C,D,X[4], 6,0xf7537e82);
	RFI(D,A,B,C,X[11],10,0xbd3af235);
	RFI(C,D,A,B,X[2],15,0x2ad7d2bb);
	RFI(B,C,D,A,X[9],21,0xeb86d391);

	buf->A+=A;		/*加上寄存器初始值*/
	buf->B+=B;
	buf->C+=C;
	buf->D+=D;
}
int main()
{
	printf("\t\t———————MD5加密工具———————\n");
	while(1)
	{
		printf("\n\n请输入要加密的字符串，回车后以ctrl+z结束：\n\n");
		BYTE Data_Block[BLOCK_BYTE_SIZE]={0};
		WORD X[BLOCK_WORD_SIZE]={0};
		BYTE Digest[16]={0};
		size_t count=5;
		unsigned _int64 MsgLenth=0;
		MD_Buffer Buf;
		Buf.A=INIT_A;
		Buf.B=INIT_B;
		Buf.C=INIT_C;
		Buf.D=INIT_D;
		while((count=fread(Data_Block,sizeof(BYTE),BLOCK_BYTE_SIZE,stdin))==BLOCK_BYTE_SIZE)
		{
			if ('\n'==Data_Block[BLOCK_BYTE_SIZE-1]) break;
			MsgLenth+=BLOCK_BIT_SIZE;
			memcpy(X,Data_Block,sizeof(WORD)*BLOCK_WORD_SIZE);
			HMD5(&Buf,X);
		}
		if (count>0)
		{
			count--;
			MsgLenth+=(count*8);
			if (count<56)	/*小于448位的情况*/
			{
				memset(Data_Block+count,0x80,sizeof(BYTE));		/*填充1*/
				memset(Data_Block+count+1,0,sizeof(BYTE)*(56-count-1));		/*填充0*/
			}
			else	/*大于等于448位的情况*/
			{
				memset(Data_Block+count,0x80,sizeof(BYTE));	/*填充1*/
				memset(Data_Block+count+1,0,sizeof(BYTE)*(BLOCK_BYTE_SIZE-count-1));	/*填充0*/
				memcpy(X,Data_Block,sizeof(WORD)*BLOCK_WORD_SIZE);
				HMD5(&Buf,X);
				memset(Data_Block,0,sizeof(BYTE)*BLOCK_BYTE_SIZE);
			}
			memcpy(X,Data_Block,sizeof(WORD)*(BLOCK_WORD_SIZE-2));	/*最后两个字留待存储消息长度*/
			memcpy(X+BLOCK_WORD_SIZE-2,&MsgLenth,sizeof(WORD)*2);	/*最后两个字保存消息长度*/
			HMD5(&Buf,X);
		}
		memcpy(Digest,&Buf.A,sizeof(WORD));
		memcpy(Digest+4,&Buf.B,sizeof(WORD));
		memcpy(Digest+8,&Buf.C,sizeof(WORD));
		memcpy(Digest+12,&Buf.D,sizeof(WORD));
		printf("MD5加密结果：\n");
		for (int i=0;i<16;i++)
		{
			printf("%02x",Digest[i]& 0xff);
		}
	}
	return 0;
}


