/*实验二：栈实现算符优先*/
/*方案一:实现了多位未实现小数*/
/*
#include "iostream"
#include "string"
#include "cmath"

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;
typedef struct {
    Node *top;
    int count;
} Link_Stack;


Link_Stack *push_stack(Link_Stack *p, int elem) {
    //p==NULL
    if (p == NULL) {
        cout << "输入Link_Stack错误" << endl;
        return NULL;
    }
        //p!=NULL
    else {
        Node *temp = new Node();
        temp->data = elem;
        //p->top!=NULL
        if (p->top != NULL) {
            temp->next = p->top;
            p->top = temp;
            p->count++;
            return p;
        }
            //p->top==NULL
        else {
            p->top = temp;
            p->count++;
            return p;
        }
    }
}

int pop_stack(Link_Stack *p) {
    //p==NULL
    if (p == NULL) {
        cout << "输入Link_Stack错误" << endl;
        return NULL;
    }
        //p!=NULL
    else {
        Node *pop = p->top;//转存当前top指针
        char data = pop->data;
        p->top = p->top->next;//top指针下移
        delete pop;//删除出栈结点
        p->count--;//count
        return data;
    }
}

void printStack(Link_Stack *p) {
    //p==NULL
    if (p == NULL) {
        cout << "输入Link_Stack错误" << endl;
        return;
    }
        //p!=NULL
    else {
        Node *current = p->top;
        while (current != NULL) {
            cout << current->data;
            current = current->next;
        }
    }
}

Link_Stack *creatStack() {
    //创建头指针结点
    Link_Stack *p = new Link_Stack();
    p->top = NULL;
    p->count = 0;
    return p;
}

void partOfEvaluate(int symbol, Link_Stack *p) {
    int a = pop_stack(p);;
    int b = pop_stack(p);
    int c;
    if (symbol == int('+' - '0')) {
        c = a + b;
    } else if (symbol == int('-' - '0')) {
        c = a - b;
    } else if (symbol == int('*' - '0')) {
        c = a * b;
    } else if (symbol == int('/' - '0')) {
        c = a / b;
    } else if (symbol == int('^' - '0')) {
        c = pow(a,b);
    } else if (symbol == int('%' - '0')) {
        c = a % b;
    } else {
        cout << "发生错误" << endl;
    }
    push_stack(p, c);
}

int evaluatePostfixExpression(string postfixExpression) {
    Link_Stack *stack = creatStack();
    int i;
    int multiBit = 0;
    for (i = 0; i < postfixExpression.size(); i++) {
        int temp = int(postfixExpression[i] - '0');
        if (temp == int(' ' - '0')) {   //用于实现多位
            int multi = multiBit;
            float result = 0;
            while (multiBit != 0) {
                int a = pop_stack(stack);
                result = result*0.1+a;
                multiBit--;
            }
            result = result*pow(10,multi-1);
            push_stack(stack, result);
        } else if (temp == '+' - '0' ||
                   temp == '-' - '0' ||
                   temp == '*' - '0' ||
                   temp == '/' - '0' ||
                   temp == '^' - '0' ||
                   temp == '%' - '0') {
            partOfEvaluate(temp, stack);
        } else {
            multiBit++;
            stack = push_stack(stack, temp);
        }
    }
    return stack->top->data;
}



int main() {

    string test = "12 100 +3*";
    cout << evaluatePostfixExpression(test) << endl;
    return 0;

}
*/

/*方案二:改变了Node存储结构，以实现小数*/
/*

#include "iostream"
#include "string"
#include "cmath"
#include "stdlib.h"


using namespace std;


typedef struct node {
    float data;
    char symbol;
    struct node *next;
} Node;
typedef struct {
    Node *top;
    int count;
} Link_Stack;


Link_Stack *push_stack(Link_Stack *p, float tData, char tSymbol) {
    //p==NULL
    if (p == NULL) {
        cout << "输入Link_Stack错误" << endl;
        return NULL;
    }
        //p!=NULL
    else {
        Node *temp = new Node();
        temp->data = tData;
        temp->symbol = tSymbol;
        //p->top!=NULL
        if (p->top != NULL) {
            temp->next = p->top;
            p->top = temp;
            p->count++;
            return p;
        }
            //p->top==NULL
        else {
            p->top = temp;
            p->count++;
            return p;
        }
    }
}

Node *pop_stack(Link_Stack *p) {
    //p==NULL
    if (p == NULL) {
        cout << "输入Link_Stack错误" << endl;
        return NULL;
    }
        //p!=NULL
    else {
        Node *pop = p->top;//转存当前top指针
        p->top = p->top->next;//top指针下移
        //delete pop;//删除出栈结点
        p->count--;//count
        return pop;
    }
}

void printStack(Link_Stack *p) {
    //p==NULL
    if (p == NULL) {
        cout << "输入Link_Stack错误" << endl;
        return;
    }
        //p!=NULL
    else {
        Node *current = p->top;
        while (current != NULL) {
            char tSymbol = current->symbol;
            if (tSymbol == '@') {
                cout << current->data;
            } else {
                cout << tSymbol;
            }
            current = current->next;
        }
    }
}

Link_Stack *creatStack() {
    //创建头指针结点
    Link_Stack *p = new Link_Stack();
    p->top = NULL;
    p->count = 0;
    return p;
}

int judgeLevelOfSymbol(char symbol) {
    int level;
    if (symbol == '(' || symbol == ')') {
        level = 1;
    } else if (symbol == '^') {
        level = 2;
    } else if (symbol == '*' || symbol == '/' || symbol == '%') {
        level = 3;
    } else if (symbol == '+' || symbol == '-') {
        level = 4;
    }
    return level;
}

bool judgmentPriority(char symbol1, char symbol2) {
    int levelSymbol1 = judgeLevelOfSymbol(symbol1);
    int levelSymbol2 = judgeLevelOfSymbol(symbol2);
    if (levelSymbol1 < levelSymbol2) {
        return true;
    } else {
        return false;
    }
}

Link_Stack *reverseStack(Link_Stack *p) {
    Link_Stack *tempStack = creatStack();
    while (p->count != 0) {
        Node *tempNode = pop_stack(p);
        push_stack(tempStack, tempNode->data, tempNode->symbol);
    }
    return tempStack;
}

//将算术表达式(中缀式)转换为逆波兰式(后缀式)
Link_Stack *convertInfixExpToPostfixExp(Link_Stack *p) {
    //符号栈
    Link_Stack *s1 = creatStack();
    //操作数栈
    Link_Stack *s2 = creatStack();
    Node *tempNode = pop_stack(p);
    //重复下面的1~4步，直至处理完所有的输入字符
    while (tempNode->symbol != '#') {
        //1.若取出的字符是操作数，则分析出完整的运算数，该操作数直接送入S2栈
        if (tempNode->symbol == '@') {
            s2 = push_stack(s2, tempNode->data, tempNode->symbol);
        }
        //2.若取出的字符是运算符，则将该运算符与S1栈栈顶元素比较
        else if (tempNode->symbol == '+' || tempNode->symbol == '-' ||
                 tempNode->symbol == '*' || tempNode->symbol == '/' ||
                 tempNode->symbol == '^' || tempNode->symbol == '%') {
                //如果该运算符(不包括括号运算符)优先级高于S1栈栈顶运算符（包括左括号）优先级则将该运算符进S1栈
            if (s1->top==NULL||judgmentPriority(tempNode->symbol, s1->top->symbol)) {
                s1 = push_stack(s1, tempNode->data, tempNode->symbol);
            }
                //否则，将S1栈的栈顶运算符弹出，送入S2栈中，直至S1栈栈顶运算符（包括左括号）低于（不包括等于）该运算符优先级时停止弹出运算符，最后将该运算符送入S1栈
            else {
                //Node *tempNode1 = pop_stack(s1);
                while (!judgmentPriority(s1->top->symbol, tempNode->symbol)) {
                    Node *tempNode1 = pop_stack(s1);
                    s2 = push_stack(s2, tempNode1->data, tempNode1->symbol);
                }
                s1 = push_stack(s1, tempNode->data, tempNode->symbol);
            }
        }
        //3.若取出的字符是“（”，则直接送入S1栈顶
        else if (tempNode->symbol == '(') {
            s1 = push_stack(s1, tempNode->data, tempNode->symbol);
        }
            //4.若取出的字符是“）”，则将距离S1栈栈顶最近的“（”之间的运算符，逐个出栈，依次送入S2栈，此时抛弃“（”
        else if (tempNode->symbol == ')') {
            Node *tempNode2 = pop_stack(s1);
            while (tempNode2->symbol != '(') {
                s2 = push_stack(s2, tempNode2->data, tempNode2->symbol);
                tempNode2 = pop_stack(s1);
            };
        } else {
            cout << "symbol出现错误" << endl;
            return NULL;
        }
        tempNode = pop_stack(p);
    }
    //若取出的字符是“#”，则将S1栈内所有运算符（不包括“#”），逐个出栈，依次送入S2
    if (tempNode->symbol == '#') {
        while (s1->count != 0 && s1->top->symbol != '#') {
            Node *tempNode4 = pop_stack(s1);
            s2 = push_stack(s2, tempNode4->data, tempNode4->symbol);
        }
    }
    s2 = reverseStack(s2);
    return s2;
}

void partOfEvaluate(char symbol, Link_Stack *p) {
    Node *a = pop_stack(p);;
    Node *b = pop_stack(p);
    float c;
    if (symbol == '+') {
        c = a->data + b->data;
    } else if (symbol == '-') {
        c = a->data - b->data;
    } else if (symbol == '*') {
        c = a->data * b->data;
    } else if (symbol == '/') {
        c = a->data / b->data;
    } else if (symbol == '^') {
        c = pow(b->data, a->data);
    } else if (symbol == '%') {
        c = int(a->data) % int(b->data);
    } else {
        cout << "计算发生错误" << endl;
    }
    push_stack(p, c, '@');
}

float evaluatePostfixExpression(Link_Stack *postfixExpression) {
    Link_Stack *p = creatStack();
    //如果逆波兰表达式不为空，重复下面1,2
    Node *temp;
    while (postfixExpression->count != 0) {

        temp = pop_stack(postfixExpression);
        //1.如果是操作数，入栈
        if (temp->symbol == '@') {
            p = push_stack(p, temp->data, temp->symbol);
        }
        //2.如果是运算符，出栈已有两个操作数，运算后入栈
        else {
            if (temp->symbol == '+') {
                partOfEvaluate('+', p);
            } else if (temp->symbol == '-') {
                partOfEvaluate('-', p);
            } else if (temp->symbol == '*') {
                partOfEvaluate('*', p);
            } else if (temp->symbol == '/') {
                partOfEvaluate('/', p);
            } else if (temp->symbol == '^') {
                partOfEvaluate('^', p);
            } else if (temp->symbol == '%') {
                partOfEvaluate('%', p);
            } else {
                cout << "出现计算错误";
                return NULL;
            }
        }
    }
    if (postfixExpression->count == 0) {
        return p->top->data;
    }
}

float getResult(Link_Stack *p) {
    p = convertInfixExpToPostfixExp(p);
    float result = evaluatePostfixExpression(p);
    return result;
}


char nullSymbol = '@';
char endSymbol = '#';
int nullData = 0;

Link_Stack *createExpress(Link_Stack * express){
    Link_Stack *p = creatStack();
    push_stack(p, nullData, endSymbol);
    while (express->count!=0){
        Node *temp=pop_stack(express);
        push_stack(p,temp->data,temp->symbol);
    }
    return p;
}

Link_Stack *convertStringToStack(string express){
    Link_Stack *p = creatStack();
    const char *temp=NULL;
    for(int i=0;i<express.size();i++){
        if( i!=0&&( express[i]=='+'||express[i]=='^'||express[i]=='*'||express[i]=='/'||express[i]=='%'||express[i]=='-'||express[i]==')')){
            temp=express.substr(0,i).data();
            float tempFloat=(float)atof(temp);
            push_stack(p, tempFloat, nullSymbol);
            push_stack(p,nullData,express[i]);
            express=express.substr(i+1,express.size());
            i=-1;
        }
        else if(i==0&&( express[i]=='+'||express[i]=='^'||express[i]=='*'||express[i]=='/'||express[i]=='%'||express[i]=='-'||express[i]==')')){
            push_stack(p,nullData,express[i]);
            express=express.substr(i+1,express.size());
            i=-1;
        }
        else if(express[i]=='('){
            push_stack(p,nullData,express[i]);
            express=express.substr(i+1,express.size());
            i=-1;
        }
        int j;
        for(j=0;j<express.size();j++){
            if( express[j]=='+'||express[j]=='^'||express[j]=='*'||express[j]=='/'||express[j]=='%'||express[j]=='-'||express[j]==')'){
                break;
            }
        }
        if(j==express.size()&&express.size()!=0){
            temp=express.substr(0,express.size()).data();
            float tempFloat=(float)atof(temp);
            push_stack(p, tempFloat, nullSymbol);
            break;
        }
    }
    p= createExpress(p);
    return p;
}

int main() {





//    Link_Stack *p = creatStack();
//    push_stack(p, 11, nullSymbol);
//    push_stack(p, nullData, '+');
//    push_stack(p, 1.7, nullSymbol);
//    p= createExpress(p);


//    Link_Stack *p = creatStack();
//    push_stack(p, 11.5, nullSymbol);
//    push_stack(p, nullData, '+');
//    push_stack(p, 2, nullSymbol);
//    push_stack(p, nullData, '^');
//    push_stack(p, 3, nullSymbol);
//    p= createExpress(p);
//    float result = getResult(p);
//    cout << result << endl;


    //11.5+2^3
    //(1+1)*2
    //(1.5+2)*3
    //1.5+2*3

    cout<<"请输入算术表达式 : "<<endl;
    string express;
    cin>>express;
    Link_Stack *p = convertStringToStack(express);
    float result = getResult(p);
    cout << "计算结果 : "<<result << endl;

    return 0;

}

*/
