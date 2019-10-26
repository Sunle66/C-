//
//预处理 gcc -E text.c -o text.i
//编译   gcc -S text.i -o text.s
//汇编。 gcc -c text.s -o text.o
//链接。 gcc text.out -o text

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
//#include<math.h>

#include"SeqList.h"

//初始化
void SeqListInit(SeqListR *pSeq){
    assert(pSeq != NULL);

    pSeq->size = 0;
}

//销毁
void SeqListDestor(SeqListR *pSeq){
    assert(pSeq != NULL);

    pSeq->size = 0;

}
//打印
void SeqListPrint(const SeqListR *pSeq){

    for(int i = 0;i < pSeq->size;i++){
        printf("%d",pSeq->array[i]);
    }
    printf("\n");
}

//尾插
void SeqListPushBack(SeqListR *pSeq,DataType data){
    assert(pSeq != NULL);

    if(pSeq->size == MAX_SIZE){
        printf("该顺序表已满，无法进行插入操作\n");
    }

    pSeq->array[pSeq->size ] = data;

    pSeq->size++;
}

//头插
void SeqListPushFront(SeqListR *pSeq,DataType data){
    assert(pSeq != NULL);

    if(pSeq->size == MAX_SIZE){
        printf("该顺序表已满，无法进行插入操作\n");
    }
#if 1 //i的含义是数据下标
    for(int i = pSeq->size - 1;i >= 0;i--){
        pSeq->array[i+1] = pSeq->array[i];
    }
#else  //j的含义是空间下标
    for(int j = pSeq->size;j > 0;j--){
        pSeq->array[j] = pSeq->array[j-1];
    }
#endif
    pSeq->array[0] = data;
    pSeq->size++;
}

//中间插入

void SeqListInsert(SeqListR *pSeq,int pos,DataType data){
    assert(pSeq != NULL);
    assert(pos >= 0&&pos < pSeq->size);
    
    if(pSeq->size == MAX_SIZE){
        printf("该顺序表已满，无法进行插入操作\n");
    }

    for(int i = pSeq->size-1;i>=pos;i--){
        pSeq->array[i+1]=pSeq->array[i];
    }

    pSeq->array[pos] = data;
    pSeq->size++;
}
//尾删
void SeqListPopBack(SeqListR *pSeq,DataType data){
    assert(pSeq != NULL);   //传入地址不为空指针
    assert(pSeq->size > 0);  //顺序表不为空

    pSeq->size--;
}
//头删
void SeqListPopFront(SeqListR *pSeq,DataType data){
    assert(pSeq != NULL);
    assert(pSeq->size > 0);

    for(int i = 0;i < pSeq->size-1;i++){
        pSeq->array[i] = pSeq->array[i+1];
    }
    pSeq->size--;
}
//从任意位置删除
void SeqListErae(SeqListR *pSeq,int pos,DataType data){
    assert(pSeq != NULL);
    assert(pSeq->size > 0);
    assert(pos >= 0&&pos < pSeq->size);

    for(int i = pos;i < pSeq->size-1;i++){
        pSeq->array[i] = pSeq->array[i+1];
    }
    pSeq->size--;
}
//排序

//稳定性：相同的顺序保证顺序不变就是稳定

//插入排序  希尔排序    选择排序：直接选择排序+堆排序        冒泡排序     快速排序    堆排序

//插入排序    直接选择排序+堆排序  冒泡排序
//减治算法：一次小的过程，解决一个数组问题，一个大的排序问题，变成n个小的过程


//插入排序
//时间复杂度。最好O(n) 平均 O(N^2) 最坏 O(n^2)
//稳定性：稳定array[j]=k，跳出循环，保证了稳定性
//
//void InsertSort(int array[],int size){
//    //可以优化成for(int i =1 ;i<size;i++)
//    for(int i = 0;i<size;i++){
//        //array[i]插入的数组
//        //从[0,i)是已经有序的区间
//        //1.array【j】<=k。break
//        //2.array[j]>k,array[j]=array[j+1]
//        //3.
//        int k = array[i];
//        int j;
//        for(j = i-1;j >= 0&&array[j] > k;j--){
//            array[j+1] = array[j];
//        }
//        array[j+1] = k;
//    }
//}
//
////希尔排序
////时间复杂度
////最好O(n)平均O(n^1.3)最差O(n^2)
////空间复杂度O(1)
////不稳定，（相同的数没法保证分在同一个数组）
////利用越有序，插排效率越大，在进行插排之前进行预排序，让数列尽可能有序，对数列依次进行分组插排
//
//
//
//
////直接选择排序
//void SelectSort(int array[],int size){
//    for(int i = 0;i < size;i++){
//        int m =0;
//        for(int j = 0;j < size - i;j++){
//            if(array[j] > array[m]){
//                m = j;
//            }
//        }
//        Swap(array + m,array+size-i-1);
//
//    }
//}
////堆排序（升序建大堆）
////
////建堆
//void CreatHeap(int array[],int size){
//
//}
//void AdjustDown(int array[],int size,int r){
//
//}
////冒泡排序
//
//void BubbleSort(int array[],int size){
//
//}
//
////快速排序
//
////1.选择则一个基准值，
////选择方法很多，目前采用最后变得一个座位基准值的方法
////2.遍历整个区间，把所有的数和基准值做比较，并进行数据移动，使得
//    //比基准值小的数放基准值左边，比基准值大的放基准值的右边
////3.分治算法
//
////      利用递归解决左右两个区间
////终止条件：1.小区间size = 0    2.小区间的数已经有序，也就是size = 1
//
//int Partion_2(int array[],int left,int right){
//
//
//
//    return 0;
//}
//
//int Partion_3(int array[],int left,int right){
//    int d = left;
//    for(int i = 0;i<right ;i++){
//        if(array[i]<array[right]){
//            Swap(array + 1,array + d);
//            d++;
//        }
//    }
//    Swap(array + d,array + right);
//    return d;
//}
////具体的线性结构
////队列。   先进先出。 列表
////应用  保证公平性（Linux 信息队列）
//        //二叉树层序遍历（BFS广度优先遍历)
//
//
////栈。  先进后出。
////应用 括号匹配 | 逆波兰表达式 | 迷宫
////二叉树链式存储
//typedef struct  TreeNode{
//    int value;
//    struct TreeNode *left;
//    struct TreeNode *right;
//
//} TreeNode;
////前序遍历
//void PredrderTraversal(TreeNode *root){
//    //根，只做打印
//    printf("%d",root->value);
//    //左子树，递归操作
//    PredrderTraversal(root->left);
//    //右子树，递归操作
//    PredrderTraversal(root->right);
//
//}
////求二叉树的高度
//int GetHeight(TreeNode *root){
//    if(root == NULL){
//        return 0;
//    }
//    int left = GetHeight(root->left);
//    int right = GetHeight(root->right);
//
//    return left >right ? left + 1:right +1;
//}
////二叉树的查找
//
////在二叉树（每个节点的value不会重复）中查找value
////如果找到，返回节点地址
////如果没有找到，返回 NULL
////查找策略
////0.如果是空树，直接返回没找到null
////1.判断根，如果根是，返回根的地址，否则
////2.去左子树继续查找,返回左子树中找到的节点地址，否则
////3.去右子树继续查找
////4.返回右子树中的查找结果，找到返回节点地址，没找到返回NULL
//TreeNode *Find(TreeNode *root,int value){
//    if(root == NULL){
//        return NULL;
//    }
//    if(root->value == value){
//        return root;
//    }
//    TreeNode *r = Find(root->left, value);
//    if(r != NULL){
//        return r;
//    }
//    return Find(root->right,value);
//}
////    if(root == NULL){
////        return NULL;
////    }else{
////        if(root->value == value){
////              return root;
////          }
////          else{
////              TreeNode *l = Find(root->left,value);
////              if(l == NULL){
////                  return l;
////              }
////          }else{
////                  TreeNode *r=Find(root->right, value);
////                  if(r==NULL){
////                      return r;
////                  }
////
////                  else{
////                      return NULL;
////                  }
////
////
////          }
//
////向下调整
//
//
////顺序表
//typedef struct SeqList{
//    int array[100];
//    int size;
//} SeqList;
////头插 时间复杂度O（n）
//void SeqListPushFront(SeqList *sl,int value){
//    for(int i = sl->size;i > 0;i++){
//        sl->array[i] = sl->array[i-1];
//    }
//    sl->array[0] = value;
//    sl->size++;
//}
////头删O(n)
//void SeqListPopFront(SeqList *sl,int value){
//    if(sl->size == 0){
//        printf("顺序表为空\n");
//    }
//    for(int i = 1;i <= sl->size;i++){
//        sl->array[i-1] = sl->array[i];
//    }
//    sl->size--;
//}
////中间插入
//void SeqListPushMiddle(SeqList *sl,int i,int value){
//    //判断插入位置是否合法
//    if(i < 1||sl->size >100){
//        printf("插入的位置不合法！\n");
//    }
//    //判断顺序表是否已满
//    if(sl->size ==100){
//        printf("顺序表已满\n");
//    }
//    for(int k = sl->size - 1;k >= i - 1;k--){
//        sl->array[k+1] = sl->array[k];
//    }
//    sl->array[i-1] = value;
//    sl->size++;
//}
////中间删除
//void SeqListDelMiddle(SeqList *sl,int i){
//    //判断顺序表是否为空
//    if(sl->size < 1){
//        printf("顺序表为空\n");
//    }
//
//    for(int k = i;k < sl->size;k++){
//        sl->array[k] = sl->array[k+1];
//    }
//    sl->size--;
//
//}
////尾插   O(1)
//void PushBack(SeqList *sl,int value){
//    if(sl->size == 100){
//        printf("顺序表已满\n");
//    }
//    sl->array[sl->size] = value;
//    sl->size++;
//}
////尾删   O(1)
//void PopBack(SeqList *sl){
//    if(sl->size == 0){
//        printf("顺序表为空\n");
//    }
//    sl->size--;
//}
////链表
//typedef struct Node{
//    int value;
//    struct Node *next;   //保存下一个节点的地址
//
//} Node;
//
//typedef struct List{
//    Node *head;
//} List;
////链表的逆置
////三个指针的遍历
//Node *Reverse_1(Node *head){         //参数的原始链表的第一个节点
//    if(head == NULL){
//        return NULL;
//    }
//    Node *p1 = NULL;
//    Node *p2 = head;//返回值是逆置后链表的第一个节点
//    Node *p3 = head->next;
//    while( p3 != NULL){
//        p2->next = p1;
//        p1 = p2;
//        p2 = p3;
//        if(p3 != NULL){
//            p3 = p3->next;
//        }
//    }
//        //三个指针的遍历
//
//    return p1;
//}
//  //头删 + 头插
//Node *Reverse_2(Node *head){
//    Node *c = head;
//    Node *next;
//    Node *newHead = NULL;
//
//    while(c!=NULL){
//        next = c->next;
//
//        c->next = newHead;
//        newHead = c;
//        c = next;
//    }
//    return newHead;
//}
////链表的尾删
//void ListPonBack(List *list){
//    assert(list->head != NULL);
//
//    if(list->head->next == NULL){
//
//    }
//    //找到倒数第二个节点，删除最后一个
//    Node *c= list->head;
//    while(c->next->next != NULL){
//        c=c->next;
//    }
//    free(c->next);
//    c->next = NULL;
//    //特殊情况的考虑
//
//
//}



//
//int ComInt(void* p1,void* p2){
//    //将 void* 强制转换为 int*
//    int* a = (int*)p1;
//    int* b = (int*)p2;
//    //如果*a>*b,数组返回值为真，否则数组返回值为假
//    return *a > *b;  //讲数组从小到大排序
//    //return *a < *b;   将数组从大到小排序
//}
//
//int main(){
//    int a[]={9,6,8,4};
//    //直接求数组占的字节
//    printf("%d\n",sizeof(a));
//    //a 隐式转换为指针，数组名不可以进行数学计算
//    printf("%d\n",sizeof(a + 0));//指针
//    printf("%d\n",sizeof(a + 1));
//    // 指向数组首元素
//    printf("%d\n",sizeof(*a));//数字
//    printf("%d\n",sizeof(a[1]));
//    printf("%d\n",sizeof(&a));//取地址变为数组指针
//    printf("%d\n",sizeof(*&a));//&a数组指针，针对数组指针解引用得到的还是原来的数组
//    printf("%d\n",sizeof(&a +1));//&a 是指针 ，加一得到的依然是指针
//    printf("%d\n",sizeof(&a[0])); //[]运算级高于&，
//    printf("%d\n",sizeof(&a[0] + 1));
//
//
////    //qsort 实现是基于快速排序
////    //qsort 是一个回调函数，参数调用顺序不由程序员来决定
////    qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),ComInt);
////    for(int i = 0;i < 4;i++){
////        printf("%d\n",arr[i]);
////    }
//    return 0;
//
//}



//
//#include<stdio.h>
//#include"Header.h"
//
//
//




//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//
//int main(){
//
//
//}




//

//
////建xiao堆
//
//void ADjustdown(int array[],int size,int root){
////    size = root*2 + 1;
//    if(root*2+1>=size){
//        //叶子结点
//
//    }
//
//    //没有有孩子->左孩子
//    //左右都有，左孩子小->左孩子
//    //左右都有，右孩子小->右孩子
//    int min = 2*root +1;
//    if(2 *root +2 < size && array[2*root+2]<array[2 * root+1]){
//        min = 2 *root +2;
//    }
//    if(array[root]<=array[min]){
//        return;
//    }
//    int t =array[min];
//    array[min] = array[root];
//    array[root] = t;
//
//    ADjustdown(array, size, min);
//}
//
//
//
//void TopK(int array[],int size,int k){
//
//}
//int maxDepth(struct TreeNode* root){
//    if(root == NULL){
//        return 0;
//    }
//    int left = maxDepth(root->left):
//    int right = maxDepth(root->right);
//    return (left > right ?left+1:right + 1);
//}
//
//bool isMirrorTree(struct TreeNode *p,struct TreeNode *q){
//    if (p == NULL && q == NULL){
//        return true;
//    }
//    if( p == NULL || q == NULL){
//        return false;
//    }
//    return p->val == q->val&&
//    p->right == p->left&&
//    p->left == p->right;
//}






//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

//#include<stdio.h>
//int mian(){
//
//    return 0;
//}


//
//#include<stdio.h>
//#include<math.h>
//int reverse_bit(unsigned int value){
//    int ret = 0;
//    int bit = 0;
//    int i = 0;
//    for(i = 0;i < 32;i++){
//        ret = ret << 1;        //左移一位，保存前一位
//        bit = value & 1;       //取出最后一位
//        value = value >> 1;    //右移一位，取下一位
//        ret = bit | ret;       //最后一位值赋给ret
//    }
//    return ret;
//}
//
//int main(){
//    printf("%u\n",reverse_bit(25));
//    return 0;
//}









//3.在屏幕上打印杨辉三角。
//   1
//  1 1
// 1 2 1
//1 3 3 1
//前提：每行端点与结尾的数为1.
//每个数等于它上方两数之和。
//每行数字左右对称，由1开始逐渐变大。
//第n行的数字有n+1项。
//第n行数字和为2n。
//第n行的m个数可表示为 C(n-1，m-1)，即为从n-1个不同元素中取m-1个元素的组合数。
//第n行的第m个数和第n-m+1个数相等 ，为组合数性质之一。
//每个数字等于上一行的左右两个数字之和。可用此性质写出整个杨辉三角。即第n+1行的第i个数等于第n行的第i-1个数和第i个数之和，这也是组合数的性质之一。即 C(n+1,i)=C(n,i)+C(n,i-1)。
//(a+b)n的展开式中的各项系数依次对应杨辉三角的第(n+1)行中的每一项。
//将第2n+1行第1个数，跟第2n+2行第3个数、第2n+3行第5个数……连成一线，这些数的和是第4n+1个斐波那契数；将第2n行第2个数(n>1)，跟第2n-1行第4个数、第2n-2行第6个数……这些数之和是第4n-2个斐波那契数。
//将各行数字相排列，可得11的n-1（n为行数）次方：1=11^0; 11=11^1; 121=11^2……当n>5时会不符合这一条性质，此时应把第n行的最右面的数字"1"放在个位，然后把左面的一个数字的个位对齐到十位... ...，以此类推，把空位用“0”补齐，然后把所有的数加起来，得到的数正好是11的n-1次方。以n=11为例，第十一行的数为：1,10,45,120,210,252,210,120,45,10,1，结果为 25937424601=1110。
//#include<stdio.h>
//#include<stdlib.h>
//
//#define N 10 //N为杨辉三角打印的行数
//
////1         row = 0；
////1 1        row = 1；
////1 2 1       row = 2；
////1 3 3 1      row = 3；         //第n行的数字有n+1项。
//int main(){
//    int row = 0;
//    int col = 0;
//    int arr[N][N];
//    //先打印每一行的第一个和最后一个
//    //每行端点与结尾的数为1.
//    for(row = 0;row < N;row++){
//        arr[row][0] = 1;
//        arr[row][row] = 1;
//    }
//    //打印中间部分
//    //每个数等于它上方两数之和
//    for(row = 2;row < N;row++){
//        for(col = 1;col < row;col++){
//            arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
////            printf("%4d",arr[row][col]);
//
//        }
//        //printf("\n");
//    }
//
//    for(row=0;row<N;row++){
//        for(col=0;col<2*(N-row);col++){
//            printf(" ");//让直角三角形变为等腰三角形
//        }
//        for(col=0;col<=row;col++){
//            printf("%4d",arr[row][col]);
//        }
//        printf("\n");
//    }
//    return 0;
//
//}




//int main(){
    //宏对参数没有类型检查，没有检查就少了一重防止错误的保证
    //但是也有一点好处，定义一个宏，就能够给多种不同数据类型的参数来使用，达到了泛型编程
    //宏相对于c语言函数的优势
    //1.宏能够实现类似于泛型编程的效果      c++ template
    //2.宏在使用的时候，没有函数调用开销    c++ inline
    //宏lq   可能会带来运算符优先级的问题，导致容易出错
    //c++ 基于template 模版，搞了一个“模版元编程”
    //google text,谷歌出品的一个c++版本的单元
//#pragma_once 保证头文件只能被包含一次
//    printf("%s,%d😊😢😓😅\n",__FILE__,__LINE__);

//    return 0;
//}


//main函数有三个版本
//1.无参数版本
//2.俩个参数的版本（int argc，char* argv[])
//int main(int argc, const char * argv[]){
//
//
//}
//3.三个参数的版本
//int main(int argc, const char* argv[],char* env[]){
//env里边的内容叫做“环境变量”，env以h空指针作为结束标记

//}

//#include<stdio.h>
//#include<stdlib.h>
////2.
////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个
////嫌疑犯的一个。以下为4个嫌疑犯的供词。
////A说：不是我。
////B说：是C。
////C说：是D。
////D说：C在胡说
////已知3个人说了真话，1个人说的是假话。
////现在请根据这些信息，写一个程序来确定到底谁是凶手。
//
//int main(){
//    int murderer;
//    for(murderer = 'a';murderer < 'e';murderer++){
//        if(((murderer != 'a')+(murderer == 'c')+(murderer == 'd')+(murderer != 'd'))==3){
//            //if括号里为真时结果为1，假为0，所以三真一假结果为3
//            printf("凶手是%c\n",murderer);
//        }
//    }
//    system("pause");
//    return 0 ;
//}







//#include<stdio.h>
//#include<stdlib.h>
////5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
////A选手说：B第二，我第三；      ----->A = 3 &&  B != 2 || A != 3  && B = 2
////B选手说：我第二，E第四；      ----->B = 2 &&  E != 4 || B != 2  && E = 4
////C选手说：我第一，D第二；     ------>C = 1 &&  D != 2 || C != 1  && D = 2    无论ABCDE为何值，ABCDE只能是1 2 3 4 5随机数的一个
////D选手说：C最后，我第三；      ----->C = 5 &&  D != 3 || C != 5  && D = 3       所以有A*B*C*D*E = 120；为定值
////E选手说：我第四，A第一；      ----->E = 4 &&  A != 1 || E != 4  && A = 1
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//
//
//
//int main(){
//    int A = 0;
//    int B = 0;
//    int C = 0;
//    int D = 0;
//    int E = 0;
//
//    for(A = 0;A < 5;A++){
//        for(B = 0;B < 5;B++){
//            for(C = 0;C < 5;C++){
//                for(D = 0;D < 5;D++){
//                    for(E = 0;E < 5;E++){
//                        if(((A == 3)+(B == 2) == 1&&
//                           (B == 2)+(E == 4) == 1&&
//                           (C == 1)+(D == 2) == 1&&
//                           (C == 5)+(D == 3) == 1&&
//                            (E == 4)+(A == 1) == 1) == 1){
//                                if(A*B*C*D*E == 120){
//                                    printf("A=%d,B=%d,C=%d,D=%d,E=%d",A,B,C,D,E);
//                                }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    system("pause");
//    return 0;
//}





//
//
//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
////通讯录,在代码中表示若干个人
//typedef struct PersonInfo{
//    char name[1024];
//    char phone[1024];
//}PersonInfo;
//
//#define SIZE 1000
//
//typedef struct AddrBook{
//    //SIZE表示通讯录中信息的上限
//    PersonInfo person_info[SIZE];
//    //需要标注那些信息有意义，那些没有意义
//    //通讯录并不是程序已启动，里面的1000条信息是有意义的
//    //[0,size)有意义的
//    int size;
//}AddrBook;
//
//AddrBook g_addr_book;
//
//enum{
//    EXIT = 0,
//    ADD,
//    DEL,
//    MODIFY,
//    FIND,     //查找
//    PRINT,    //打印所有信息
//    CLEAR,    //清除
//};
//
//
//
////初始化通讯录
//void Init(){
//    g_addr_book.size = 0;
//}
//
////打印一个菜单，提示用户进行操作
//int Menu(){
//    printf("欢迎来到通讯录😄： \n");
//    printf("**************************************\n");
//    printf("---------    1,添加信息    🏡----------\n");
//    printf("---------    2,删除信息    ❌----------\n");
//    printf("---------    3.修改信息    ✒️----------\n");
//    printf("---------    4.查找信息    🍵----------\n");
//    printf("---------    5.显示信息    💻----------\n");
//    printf("---------    6.清除信息    🆑----------\n");
//    printf("---------    0.退出系统    ㊗️----------\n");
//    printf("**************************************\n");
//    printf("请输入您的选择:");
//    int choice = 0;
//    scanf("%d",&choice);
//    return choice;
//}
////操作函数
//
//
//void ADDPersonInfo(){
////添加一个用户信息，提示用户进行输入
//    if(g_addr_book.size >= SIZE){//判断通讯录名额的有无
//        printf("对不起，您的通讯录已满，添加失败!\n");
//        return;
//    }
//    printf("添加一个新用户！\n");
//
//    printf("请输入新用户的姓名：\n");
//    //printf("请输入新用户的联系方式：\n");
//    scanf("%s",g_addr_book.person_info[g_addr_book.size].name);
//    printf("请输入新用户的联系方式：\n");
//    scanf("%s",g_addr_book.person_info[g_addr_book.size].phone);
//    g_addr_book.size++;
//    printf("插入成功\n");
//    printf("-----------------\n");
//
//    return;
//}
//void DELPersonInfo(){
//    //选择一个用户信息，进行删除操作
//
//
//}
//void MODIFYPersonInfo(){
//
//}
//void FINDPersonInfo(){
//
//}
//void PRINTPersonInfo(){
////打印通讯录中的所有用户信息
//    printf("打印通讯录中的所有用户信息!\n");
//    printf("-----------------------\n");
//    printf("打印完成，请您进行查看。\n");
//    for(int i = 0;i < g_addr_book.size;++i){
//        printf("[%d]%s %s\n",i,g_addr_book.person_info[i].name,
//               g_addr_book.person_info[i].phone);
//    }
//    printf("一共打印了 %d 条信息。\n",g_addr_book.size);
//    printf("------------------------\n");
//}
//void CLEARPersonInfo(){
//
//}
//int main(){
//    //先创建一个通讯录的变量，并且初始化
//    Init();
//    while(1){
//        int choice = Menu();
//    //2,进入循环，打印一个用户菜单，并且提示用户进行操作
//    // 增删查改
//    //用户输入编号后，调用相应的函数，完成具体操作
//        switch(choice){
//            case ADD:
//                ADDPersonInfo();
//                break;
//            case DEL:
//                DELPersonInfo();
//                break;
//            case MODIFY:
//                MODIFYPersonInfo();
//                break;
//            case FIND:
//                FINDPersonInfo();
//                break;
//            case PRINT:
//                PRINTPersonInfo();
//                break;
//            case CLEAR:
//                CLEARPersonInfo();
//                break;
//            case EXIT:
//                printf("欢迎使用，下次再见！👋 ");
//                break;
//            default:
//                break;
//        }
////        break;
//    }
//
//
//
//    return 0 ;
//
//}

//int main(int argc, const char * argv[]){
//    int money = 0; //钱
//    int total = 0; //喝的y水
//    int empty = 0; //空瓶
//    printf("有多少钱：");
//    scanf("%d\n",&money);
//    total = money;
//    empty = money;
//    while(empty > 1){
//        //空瓶换的汽水量
//        total = total / 2;
//        //下次可用的空瓶，保留上次没有用的空瓶
//        empty = empty / 2 + empty % 2;
//
//    }
//    printf("%d",total);
//    return 0 ;
//}
