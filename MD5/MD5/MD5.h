#ifndef MD5_H
#define MD5_H
#include <string.h>
typedef unsigned int WORD;	/*字*/
typedef char BYTE;			/*字节*/
typedef struct mdbuf		/*缓冲区*/
{
	WORD A,B,C,D;
}MD_Buffer;

#define BLOCK_BIT_SIZE 512	/*一个分组的比特数*/
#define BLOCK_BYTE_SIZE 64	/*一个分组的字节数*/
#define BLOCK_WORD_SIZE 16	/*一个分组的字数*/
#define INIT_A 0x67452301	/*寄存器A的初始值*/
#define INIT_B 0xEFCDAB89	/*寄存器B的初始值*/
#define INIT_C 0x98BADCFE	/*寄存器C的初始值*/
#define INIT_D 0x10325476	/*寄存器D的初始值*/

#define F(b,c,d) (((b)&(c))|(~(b)&(d)))
#define G(b,c,d) (((b)&(d))|((c)&~(d)))
#define H(b,c,d) ((b)^(c)^(d))
#define I(b,c,d) ((c)^((b)|~(d)))

#define ROL(n,s) ((n)<<(s))|(n)>>(32-(s))	/*循环左移s位*/
#define RFF(A,B,C,D,Xk,s,Ti)	{A+=F(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*第一轮*/
#define RFG(A,B,C,D,Xk,s,Ti)	{A+=G(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*第二轮*/
#define RFH(A,B,C,D,Xk,s,Ti)	{A+=H(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*第三轮*/
#define RFI(A,B,C,D,Xk,s,Ti)	{A+=I(B,C,D)+Xk+Ti;A=ROL(A,s);A+=B;}	/*第四轮*/
#endif

