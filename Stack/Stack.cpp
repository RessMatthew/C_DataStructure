/*ʵ�����ջʵ���������*/
/*����һ:ʵ���˶�λδʵ��С��*/
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
        cout << "����Link_Stack����" << endl;
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
        cout << "����Link_Stack����" << endl;
        return NULL;
    }
        //p!=NULL
    else {
        Node *pop = p->top;//ת�浱ǰtopָ��
        char data = pop->data;
        p->top = p->top->next;//topָ������
        delete pop;//ɾ����ջ���
        p->count--;//count
        return data;
    }
}

void printStack(Link_Stack *p) {
    //p==NULL
    if (p == NULL) {
        cout << "����Link_Stack����" << endl;
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
    //����ͷָ����
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
        cout << "��������" << endl;
    }
    push_stack(p, c);
}

int evaluatePostfixExpression(string postfixExpression) {
    Link_Stack *stack = creatStack();
    int i;
    int multiBit = 0;
    for (i = 0; i < postfixExpression.size(); i++) {
        int temp = int(postfixExpression[i] - '0');
        if (temp == int(' ' - '0')) {   //����ʵ�ֶ�λ
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

/*������:�ı���Node�洢�ṹ����ʵ��С��*/
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
        cout << "����Link_Stack����" << endl;
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
        cout << "����Link_Stack����" << endl;
        return NULL;
    }
        //p!=NULL
    else {
        Node *pop = p->top;//ת�浱ǰtopָ��
        p->top = p->top->next;//topָ������
        //delete pop;//ɾ����ջ���
        p->count--;//count
        return pop;
    }
}

void printStack(Link_Stack *p) {
    //p==NULL
    if (p == NULL) {
        cout << "����Link_Stack����" << endl;
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
    //����ͷָ����
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

//���������ʽ(��׺ʽ)ת��Ϊ�沨��ʽ(��׺ʽ)
Link_Stack *convertInfixExpToPostfixExp(Link_Stack *p) {
    //����ջ
    Link_Stack *s1 = creatStack();
    //������ջ
    Link_Stack *s2 = creatStack();
    Node *tempNode = pop_stack(p);
    //�ظ������1~4����ֱ�����������е������ַ�
    while (tempNode->symbol != '#') {
        //1.��ȡ�����ַ��ǲ�����������������������������ò�����ֱ������S2ջ
        if (tempNode->symbol == '@') {
            s2 = push_stack(s2, tempNode->data, tempNode->symbol);
        }
        //2.��ȡ�����ַ�����������򽫸��������S1ջջ��Ԫ�رȽ�
        else if (tempNode->symbol == '+' || tempNode->symbol == '-' ||
                 tempNode->symbol == '*' || tempNode->symbol == '/' ||
                 tempNode->symbol == '^' || tempNode->symbol == '%') {
                //����������(���������������)���ȼ�����S1ջջ������������������ţ����ȼ��򽫸��������S1ջ
            if (s1->top==NULL||judgmentPriority(tempNode->symbol, s1->top->symbol)) {
                s1 = push_stack(s1, tempNode->data, tempNode->symbol);
            }
                //���򣬽�S1ջ��ջ�����������������S2ջ�У�ֱ��S1ջջ������������������ţ����ڣ����������ڣ�����������ȼ�ʱֹͣ�������������󽫸����������S1ջ
            else {
                //Node *tempNode1 = pop_stack(s1);
                while (!judgmentPriority(s1->top->symbol, tempNode->symbol)) {
                    Node *tempNode1 = pop_stack(s1);
                    s2 = push_stack(s2, tempNode1->data, tempNode1->symbol);
                }
                s1 = push_stack(s1, tempNode->data, tempNode->symbol);
            }
        }
        //3.��ȡ�����ַ��ǡ���������ֱ������S1ջ��
        else if (tempNode->symbol == '(') {
            s1 = push_stack(s1, tempNode->data, tempNode->symbol);
        }
            //4.��ȡ�����ַ��ǡ��������򽫾���S1ջջ������ġ�����֮���������������ջ����������S2ջ����ʱ����������
        else if (tempNode->symbol == ')') {
            Node *tempNode2 = pop_stack(s1);
            while (tempNode2->symbol != '(') {
                s2 = push_stack(s2, tempNode2->data, tempNode2->symbol);
                tempNode2 = pop_stack(s1);
            };
        } else {
            cout << "symbol���ִ���" << endl;
            return NULL;
        }
        tempNode = pop_stack(p);
    }
    //��ȡ�����ַ��ǡ�#������S1ջ���������������������#�����������ջ����������S2
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
        cout << "���㷢������" << endl;
    }
    push_stack(p, c, '@');
}

float evaluatePostfixExpression(Link_Stack *postfixExpression) {
    Link_Stack *p = creatStack();
    //����沨�����ʽ��Ϊ�գ��ظ�����1,2
    Node *temp;
    while (postfixExpression->count != 0) {

        temp = pop_stack(postfixExpression);
        //1.����ǲ���������ջ
        if (temp->symbol == '@') {
            p = push_stack(p, temp->data, temp->symbol);
        }
        //2.��������������ջ�����������������������ջ
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
                cout << "���ּ������";
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

    cout<<"�������������ʽ : "<<endl;
    string express;
    cin>>express;
    Link_Stack *p = convertStringToStack(express);
    float result = getResult(p);
    cout << "������ : "<<result << endl;

    return 0;

}

*/
