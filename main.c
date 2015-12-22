#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//#define _FIRST_VALUES_
//#define _RANDOM_NUMBERS_
//#define _SIZE_OF_TYPES_AND_POINTERS_
//#define _FUNC_POINTER_FACTORIAL_
//#define _INC_DEC_POINTER_STRUCT_
//#define _POINTER_STRUCT_ARRAY_FUNC_
//#define _POINTER_TO_POINTER_
//#define _STRUCT_TO_ARRAY_
//#define _2D_ARRAYS_
//#define _STRUCTES_
//#define _UNION_AND_ENUM_
//#define _MACROS_


#ifdef  _FIRST_VALUES_

#define SIZE 10		// globallerin ilk degeri her zaman 0 dır
int g[SIZE];
int main()
{
	int y[SIZE];	// yerellerin ilk değeri çöp değerdir.
	int i;

	for (i = 0; i < SIZE; ++i)
		printf("g[%d] = %d\n", i, g [i]);
	for (i = 0; i < SIZE; ++i)
		printf("y[%d] = %d\n", i, y [i]);
	return 0;
}
#endif /*_FIRST_VALUES_*/

#ifdef _RANDOM_NUMBERS_

#define SIZE 10

#define RAND_SCALA 100

int main()	// dizi işlemleri
{
	int a[SIZE],temp;
	int toplam = 0;
	int k, min,i;

	srand(time(0));						// rastgele sayı üretimi(rand()) için tohum değeri zamana bağlı değiştiriliyor

	for (k = 0; k < SIZE; ++k) {

		a[k] = rand() % RAND_SCALA;
		printf("%d\n", a[k]);
	}

	for (k = 0; k < SIZE; ++k)
		toplam += a[k];

	printf("\nDizi elemanlari toplami = %d\n", toplam);

	min = a[0];
	for (k = 1; k < SIZE; ++k)
		if (min > a[k])
			min = a[k];

	printf("\nEn kucuk eleman = %d\n", min);

	printf("\nBuyukten kucuge sıralar isek;\n");

	for (i = 0; i < SIZE - 1; ++i){
		for (k = 0; k < SIZE -1 - i; ++k){
			if (a[k] < a[k + 1]) {
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
		}
	}
	for (k = 0; k < SIZE; ++k)
		printf("%d\n", a[k]);

	return 0;
}
#endif /*_RANDOM_NUMBERS_*/

#ifdef _SIZE_OF_TYPES_AND_POINTERS_

int main() 														//sizeof() Tür boyutları ve Pointer bilgisi
{
	char *cp, ch;
	int *ip, i;
	double *dp, d;
	printf("sizeof(ch)       = %u\n", sizeof(ch));
	printf("sizeof(i)        = %u\n", sizeof(i));
	printf("sizeof(d)        = %u\n", sizeof(d));
	printf("sizeof(cp)       = %u\n", sizeof(cp));
	printf("sizeof(ip)       = %u\n", sizeof(ip));
	printf("sizeof(dp)       = %u\n", sizeof(dp));
	printf("sizeof(char)     = %u byte\n", sizeof(char));
	printf("sizeof(int)      = %u byte\n", sizeof(int));
	printf("sizeof(long)     = %u byte\n", sizeof(long));
	printf("sizeof(double)   = %u byte\n", sizeof(double));
	printf("sizeof(char *)   = %u\n", sizeof(char *));
	printf("sizeof(int *)    = %u\n", sizeof(int *));
	printf("sizeof(double *) = %u\n", sizeof(double *));
	return 0;
}
#endif /*_SIZE_OF_TYPES_AND_POINTERS_*/

#ifdef _FUNC_POINTER_FACTORIAL_

void factorial(int n, long *p);

int main()
{
	long a;
	int k;
	for (k = 0; k < 14; ++k) {
		factorial(k, &a);
		printf ("%2d! = %ld\n", k, a);
	}
	return 0;
}

void factorial(int n, long *p)
{
	*p = 1;
	if (n == 0 || n == 1)
		return;
	while (n > 1)
		*p *= n--;
}
#endif /*_FUNC_POINTER_FACTORIAL_*/

#ifdef _INC_DEC_POINTER_STRUCT_

int main() 																	// ++ işleci ile pointer ve dizi atamaları
{
	int c[5] = {1, 2, 3, 4, 5};
	int d[5] = {1, 2, 3, 4, 5};
	int k;
	int *ptr = c;
	int *ptr1 = d;

	*ptr++ = 10;
	*ptr = 20;

	*++ptr1 = 10;
	*ptr1 = 20;

	printf("ptr/c[5] = {");
	for (k = 0; k < 5; ++k)
		printf("%2d ", c[k]);
	printf("}");

	printf("\n");

	printf("ptr1/d[5] = {");
	for (k = 0; k < 5; ++k)
		printf("%2d ", d[k]);

	printf("}\n");

	int a = 10;
	int b = ++a;
	printf("a = %d b = %d\n", a, b);
	a = 10;
	b = a++;
	printf("a = %d b = %d\n", a, b);
	return 0;
}

#endif /*_INC_DEC_POINTER_STRUCT_*/

#ifdef _POINTER_STRUCT_ARRAY_FUNC_

void func(int *p){

	*p = 10;//p[0] = 10; ile aynıdır

}
void func1(int *p,int n){

	*(p+n) = 10;//p[n] = 10 ile aynıdır

}

void display_array (const int *p, int size)
{
	int i;
	for (i = 0; i < size; ++i)
		printf("%d ", p[i]);
	printf("\n");
}
void set_random_array(int *ptr, int size, int max_val)
{
	int k;
	for (k = 0; k < size; ++k)
		ptr[k] = rand() % (max_val + 1);
}
void sort_array(int *ptr, int size)
{
	int i, k, temp;
	for (i = 0; i < size - 1; ++i)
		for (k = 0; k < size - 1 - i; ++k)
		if (ptr[k] > ptr[k + 1]) {
			temp = ptr[k];
			ptr[k] = ptr[k + 1];
			ptr[k + 1] = temp;
		}
}
int *getmax(int *p, int size)
{
	int *pmax, i;
	pmax = &p[0];//(int *)p ile aynı
	for (i = 1; i < size; ++i)
		if (p[i] > *pmax)
			pmax = (int *)(p + i);//pmax = &p[i]; ile aynı anlamda
	return pmax;
}

int main()																				//  pointer (dizi,fonksiyon)
{
	char k[]="GesTeknik";
	int *ptr;
	int x = 20,m[10] = {0};
	ptr = &x;
	int size = (sizeof(m)/sizeof(m[0]));
	printf("x nesnesinin adresi         = %p\n", &x);
	printf("ptr değişkeninin değeri     = %p\n", ptr);
	printf("*ptr değeri, yani x         = %d\n", *ptr);
	printf("ptr nesnesinin adresi, &ptr = %p\n", &ptr);
	func(&x);
	printf("func(&x)'ten sonra x 	    = %d\n", x);
	printf("k değeri                    = %s\n", k);
	printf("*k değeri                   = %c\n", *k);
	printf("*(k+3) değeri               = %c\n", *(k+3));
	printf("m[2] *(m+2) ile yazdırılıyor= %d\n", *(m+2));
	func1(m,2);
	printf("func1(m,2)'den sonra *(m+2) = %d\n", *(m+2));
	printf("m[0] = %d\n", m[0]);
	func(m);
	printf("func(m)'den sonra m[0] = %d\n\n", m[0]);
	printf("%d\n", &m[9] - &m[0]);
	printf("%d\n", &m[9] - &m[3]);
	printf("%d\n", &m[9] - &m[2]);
	set_random_array(m,size,100 );
	sort_array(m, size);
	printf("dizi siralama isleminden sonra yazdiriliyor!\n");
	display_array(m,size );
	printf("m(max) = %d\n", *getmax(m, size));
	printf("--------------------------------------------\n");
	int a[5] = {1, 2, 3, 4, 5};
	int *ptr1 = a + 2;
	printf("ptr1[-1] =%d\n", ptr1[-1]);
	printf("ptr1[ 0] =%d\n", ptr1[0]);
	printf("ptr1[ 1] =%d\n", ptr1[1]);

	int s = 0x00000001;
	if (*(char *)&s)// (char *) ile LSB değerine ulaşıcak tür dönüşümü yapılıo
	printf("little endian\n");//s 2 byte ve x = &s olmak üzere LSB x ,MSB x+1 dir
	else
	printf("big endian\n");
	return 0;
}
#endif /*_POINTER_STRUCT_ARRAY_FUNC_*/

#ifdef _POINTER_TO_POINTER_

int main()																				// Pointer to pointer (int **)
{
	int x = 10;
	int y = 20;
	int *p;
	int **pp;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	p = &x;
	*p = 100;				// x=100;
	pp = &p;				//pp = p nin adresi
	*pp = &y;				//pp nin gösterdiği adres p = &y
	*p = 200;				//y=200;
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	**pp = 2000;//pp nin gösterdiği adresteki gösterilen adres olan y = 2000; atıldı.
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	return 0;
}
#endif /*_POINTER_TO_POINTER_*/

#ifdef _STRUCT_TO_ARRAY_

#define		SELECTOR_DEFAULT		200
#define		SELECTOR_MIN			100
#define		SELECTOR_MAX			300

typedef struct _AirQualityRegs{

	char				InSelector:1;
	char				Rsv		  :7;
	uint8_t				Val;
	uint16_t 			LowLimit;
	uint16_t			HighLimit;
}AirQualityRegs_t;

typedef struct _AirQuality{

	AirQualityRegs_t	Regs;
	uint16_t			(*InValFunc)(void);
	uint8_t  			ModbusOffset;
	uint8_t  			Status;
}AirQuality_t;

AirQualityRegs_t AirQualityRegs;
AirQualityRegs_t *pAirQualityRegs = &AirQualityRegs;

AirQuality_t AirQuality;
AirQuality_t *pAirQuality = &AirQuality;


uint16_t	AirQualityDefaultValues[] = {

		SELECTOR_DEFAULT,
		0,
		SELECTOR_MIN,
		SELECTOR_MAX
};


int main(){																				// dizi struct arası işlem

	int i = 0;

	uint16_t *Dest = pAirQualityRegs;//pAirQuality.Regs;
	uint16_t *Src = AirQualityDefaultValues;

	for(i=0;i<4;i++)
		printf("Dest[%d]= %2d \n",i,*(Dest+i));
	printf("\n");

	for(i=0;i<4;i++)
		printf("Src [%d]= %2d \n",i,*(Src+i));
	printf("\n");

	for(i=0;i<4;i++){
		*(Dest+i) = *(Src+i);
		printf("Dest[%d]= %2d \n",i,*(Dest+i));
	}

	return 0;
}
#endif /*_STRUCT_TO_ARRAY_*/

#ifdef _2D_ARRAYS_

#define SCENARIO_SIZE 2

uint8_t Scenario[4][SCENARIO_SIZE] = {
	0,
	0,

	1,
	2,

	3,
	4,

	5,
	6

};
void InitSelector(uint8_t (*pScenario)[SCENARIO_SIZE], uint8_t *pSelector, uint8_t number)
{

	uint8_t i;

	for(i = 0; i < SCENARIO_SIZE; i++){

		pSelector[i] = pScenario[number][i];

	}

}

int main(){																						// 2 boyutlu dizi [][]

	int i;
	uint8_t pslc[SCENARIO_SIZE]={0};
	int Snumber = 3;

	InitSelector(Scenario,pslc,Snumber);

	for(i = 0; i < SCENARIO_SIZE; i++){

		printf("%2d ", pslc[i]);

	}
	return 0;

}
#endif /*_2D_ARRAYS_*/

#ifdef _STRUCTES_

int Scenario1[3];

struct Sample{
	double d;
	char c;
	long l;
}sam,sam2,*psam;//sam tanımlaması burda yapılınca
//struct Sample sam;// buna gerek kalmaz

int main()																						// Struct ve özellikleri
{
	printf("sizeof(sam)          = %u byte\n", sizeof(sam));
	printf("sam  'in adresi      = %p\n", &sam);  //(struct Sampe *) türünden pointer &sam ,türü farklı olan -
	printf("sam.d'nin adresi     = %p\n", &sam.d);//(double *) türünden pointer &sam.d ikisininde adresi aynıdır.
	printf("sam.c'nin adresi     = %p\n", &sam.c);
	printf("sam.l'nin adresi     = %p\n", &sam.l);
	printf("sizeof(char)         = %u byte\n", sizeof(char));
	printf("sizeof(int)          = %u byte\n", sizeof(int));
	printf("sizeof(long)         = %u byte\n", sizeof(long));
	printf("sizeof(double)       = %u byte\n", sizeof(double));
	printf("Sistemin 1 adresi    = %u bit\n", (sizeof(&Scenario1[0])*8));
	printf("sizeof(Scenario1)     = %u byte\n", sizeof(Scenario1));
	printf("&Scenario1[0]         = %p\n", &Scenario1[0]);
	printf("&Scenario1[1]         = %p\n", &Scenario1[1]);
	printf("&Scenario1[2]         = %p\n", &Scenario1[2]);

	sam.d = 10.0; sam.c = 20; sam.l = 30;
	printf("sam.d = %f\n", sam.d);
	printf("sam.c = %d\n", sam.c);
	printf("sam.l = %ld\n", sam.l);
	sam2 = sam;							// yapıların birbirlerine atılması
	printf("sam2.d = %f\n", sam2.d);
	printf("sam2.c = %d\n", sam2.c);
	printf("sam2.l = %ld\n\n", sam2.l);

	psam = &sam;

	printf("&sam.d= %d\n", &sam.d);
	printf("&sam.c= %d\n", &sam.c);
	printf("&sam.l= %d\n\n", &sam.l);

	printf("sam.d = %d\n", (psam));
	printf("sam.c = %d\n", (psam+1));  //psam+1 de adres değeri 1 değil sizeof(sam) kadar yani (0x10)16 arttırılır.
	printf("sam.l = %d\n\n", (psam+2));//sam.d,c,l adreslerine ve burda yazdırılan değerlere bak taşma var

	printf("sam.d = %f\n", *(psam));
	printf("sam.c = %d\n", *(psam+2));//dolayısıyla sam.c ye ulaşılamaz.
	printf("sam.l = %ld\n\n", *(psam+6));
	unsigned char *p = psam;
	printf("sam.d = %d\n", (p));
	printf("sam.c = %d\n", (p+8)); //p+1 de adres degeri 1 artar çünkü char * türündendir
	printf("sam.l = %d\n\n", (p+12));//sam.d,c,l adreslerine ve burda yazdırılan değerlere bak eşitlik var

	printf("sam.d = %f\n", *(p));
	printf("sam.c = %d\n", *(p+8));// dolayısıyla sam.c ve sam.l ye ulaşılabilir
	printf("sam.l = %ld\n", *(p+12));
	return 0;
}

#endif /*_STRUCTES_*/

#ifdef _UNION_AND_ENUM_

typedef union {
	char ch;
	int i;
	double d;
	char s[4];
}Data;

typedef struct {
	unsigned char LSB_low_byte;
	unsigned char LSB_high_byte;
	unsigned char MSB_low_byte;
	unsigned char MSB_high_byte;
}Word;

typedef union {
	unsigned int all;	//1*int =4byte
	Word w;				//4*char=4byte
}Wordform;

typedef struct _Digital{

	unsigned char D1:1;
	unsigned char D2:1;
	unsigned char D3:1;
	unsigned char D4:1;
	unsigned char MSB:4;

}Bits_t;


typedef union _Flags{

	Bits_t bits;
	unsigned char all;

}Byte_t;

enum Days{
	MON=0x31,
	THU,
	WED,
	THR,
	FRI,
	SAT,
	SUN
};
typedef enum {FALSE, TRUE} Bool;

int main()																		// union ve enum işlemleri
{
	Data data;		// union
	printf("&data    = %p\n", &data);
	printf("&data.ch = %p\n", &data.ch);
	printf("&data.i  = %p\n", &data.i);
	printf("&data.d  = %p\n", &data.d);
	printf("data.s   = %p\n", data.s);

	Wordform wf;	////bölgesel struct ve union kullanımı
	wf.w.LSB_low_byte = 0x78;
	wf.w.LSB_high_byte = 0x56;
	wf.w.MSB_low_byte = 0x34;
	wf.w.MSB_high_byte = 0x12;
	printf("wf = %x\n", wf.all);
	wf.all = 0;				//union ın tüm elemanlarına atama
	printf("wf = %x\n", wf.all);

	Byte_t Input;		//bitsel struct ve union kullanımı
	printf("sizeof(Input) = %d\n", sizeof(Input));
	Input.all = 0xFF;
	printf("Input = %2x\n", Input.all);
	Input.bits.MSB=0;
	printf("Input = %2x\n", Input.all);
	Input.bits.D1 =0;
	Input.bits.D3 =0;
	printf("Input = %2x\n", Input.all);
	Input.bits.D1 =1;
	Input.bits.MSB=1;
	printf("Input = %2x\n", Input.all);

	Bool x = FALSE;		// enum
	printf("x = %d\n", x);
	x = TRUE;
	printf("x = %d\n", x);
	printf("sizeof(x) = %d\n", sizeof(x));

	switch(getchar()){

	case MON:
		printf("Pazartesi");
	break;

	}
	return 0;
}

#endif /*_UNION_AND_ENUM_*/

#ifdef _MACROS_

#define KARE(a)      ((a)*(a))
#define randomize()  (srand((unsigned int)time(NULL)))
#define random()     (rand() % 10)
#define printInt(x)  printf(#x " = %d\n", x);//#<argümanı "" içine alır yani ("x" "=...")
#define MAX 30
int main (){																		//makro işlemleri

	int x=0;

	x=10;
	randomize();

	printInt(KARE(x));
	printInt(random());

#if MAX > 10 && MAX <= 20
	printf("(if)%d\n", MAX);
#elif MAX > 20 && MAX <= 50
	printf("(elif1)%d\n", MAX);
#elif MAX > 50 && MAX < 100
	printf("(elif2)%d\n", MAX);
#else
	printf("(else)%d\n", MAX);
#error AAAA
#endif

	printf("kaynak dosya ismi : %s\n", __FILE__);
	printf("derleme tarihi = %s\n", __DATE__);
	printf("derleme zamani = %s\n", __TIME__);
	printf("bu satirin numarasi = %d\n", __LINE__);

#ifdef __STDC__
	printf("standart C derleyicisi\n");
#else
	printf("standart C derleyicisi degil\n");
#endif
	return 0;
}
#endif /*_MACROS_*/
