#ifndef MD5_H
#define MD5_H
#include <string.h>
typedef unsigned int WORD;	/*��*/
typedef char BYTE;			/*�ֽ�*/
typedef struct mdbuf		/*������*/
{
	WORD A,B,C,D;
}MD_Buffer;

#define BLOCK_BIT_SIZE 512	/*һ������ı�����*/
#define BLOCK_BYTE_SIZE 64	/*һ��������ֽ���*/
#define BLOCK_WORD_SIZE 16	/*һ�����������*/
#define INIT_A 0x67452301	/*�Ĵ���A�ĳ�ʼֵ*/
#define INIT_B 0xEFCDAB89	/*�Ĵ���B�ĳ�ʼֵ*/
#define INIT_C 0x98BADCFE	/*�Ĵ���C�ĳ�ʼֵ*/
#define INIT_D 0x10325476	/*�Ĵ���D�ĳ�ʼֵ*/

#define F(b,c,d) (((b)&(c))|(~(b)&(d)))
#define G(b,c,d) (((b)&(d))|((c)&~(d)))
#define H(b,c,d) ((b)^(c)^(d))
#define I(b,c,d) ((c)^((b)|~(d)))

#define ROL(n,s) ((n)<<(s))|(n)>>(32-(s))	/*ѭ������sλ*/
#define RFF(A,B,C,D,Xk,s,Ti)	{A+=F(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*��һ��*/
#define RFG(A,B,C,D,Xk,s,Ti)	{A+=G(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*�ڶ���*/
#define RFH(A,B,C,D,Xk,s,Ti)	{A+=H(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*������*/
#define RFI(A,B,C,D,Xk,s,Ti)	{A+=I(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*������*/
#endif

