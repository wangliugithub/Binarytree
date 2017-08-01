

/*#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;
template<class Type>
const Type &Max(const Type &a,const Type &b)
{
	return a>b? a:b;
}
//������(binary tree)
typedef char elemtype;
typedef struct BtNode
{
	elemtype data;
	BtNode *leftchild;
	BtNode *rightchild;

}BtNode,*BinaryTree;
BtNode *Buynode()
{
	BtNode *ptree = (BtNode *)malloc(sizeof(BtNode));
	if (NULL == ptree)
		exit(1);
	memset(ptree,0,sizeof(ptree));
	return ptree;
}
void FreeNode(BtNode *ptree)
{
	free(ptree);
}
//��������������ݹ�
void PreOrder(BtNode *ptree)
{
	if (ptree != NULL)
	{
		cout<<ptree->data<<" ";
		PreOrder(ptree->leftchild);
		PreOrder(ptree->rightchild);
	}
}
//��������������ݹ�
void InOrder(BtNode *ptree)
{
	if (ptree != NULL)
	{
		InOrder(ptree->leftchild);
		cout<<ptree->data<<" ";
		InOrder(ptree->rightchild);
	}
}
//��������������ݹ�
void PastOrder(BtNode *ptree)
{
	if (ptree != NULL)
	{
		PastOrder(ptree->leftchild);
		PastOrder(ptree->rightchild);
		cout<<ptree->data<<" ";
	}
}
//����������
BtNode * creat_tree()
{
	elemtype x;
	cin>>x;
	BtNode *p = NULL;
	if (x != '#')
	{
		p = Buynode();
		p->data = x;
		p->leftchild = creat_tree();
		p->rightchild = creat_tree();
	}
	return p;
}
BtNode *creat_tree2(char *&str)
{
	BtNode *p = NULL;
	if (str != NULL && *str != '#')
	{
		p = Buynode();
		p->data = *str;
		p->leftchild = creat_tree2(++str);
		p->rightchild = creat_tree2(++str);
	}
	return p;
}
BtNode *creat_tree3(char ** const str)
{
	BtNode *p = NULL;
	if (str != NULL && *str != NULL && **str != '#')
	{
		p = Buynode();
		p->data = **str;
		p->leftchild = creat_tree3(&++(*str));
		p->rightchild = creat_tree3(&++(*str));
	}
	return p;

}
void creat_tree4(BtNode *&ptree,char *&str)
{
	if (str == NULL || *str == '#')
	{
		ptree = NULL;
	}
	else
	{
		ptree = Buynode();
		ptree->data = *str;
		creat_tree4(ptree->leftchild,++str);
		creat_tree4(ptree->rightchild,++str);
	}
}                   
void creat_tree5(BtNode **const ptree,char* &str)
{
	if (str == NULL || *str == '#')
	{
		*ptree = NULL;
	}
	else
	{
		*ptree = Buynode();
		(*ptree)->data = *str;
		creat_tree5(&(*ptree)->leftchild,++str);
		creat_tree5(&(*ptree)->rightchild,++str);
	}
}
int findindex(char *str,char ch,int n)
{
	if (str == NULL)
		exit(1);
	for (int i = 0;i<n;++i)
	{
		if (str[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

//���ȸ����и�����������
BtNode *createPI(char *ps,char *is,int n)
{
	BtNode *ptree = NULL;
	if (n>0)
	{
		ptree = Buynode();
		ptree->data = ps[0];
		int pos = findindex(is,ps[0],n);
		if (pos == -1)
			exit(1);
		ptree->leftchild = createPI(ps+1,is,pos);
		ptree->rightchild = createPI(ps+pos+1,is+pos+1,n-pos-1);
	}
	return ptree;
}

BtNode * create_IP(char *p,char *s,int n) 
{
	if (p == NULL || s == NULL || n<1)
	{
		return NULL;
	}
	else 
		return createPI(p,s,n);
}
//���и��ͺ������������
BtNode *createIL(char *is,char *ls,int n)
{
	BtNode *p = NULL;
	if (n>0)
	{
		char ch = ls[n-1];
		int index = findindex(is,ch,n);
		p = Buynode();
		p->data = ch;
		p->leftchild = createIL(is,ls,index);
		p->rightchild = createIL(is+index+1,ls+index,n-index-1);

	}
	return p;
}
BtNode *create_IL(char *is,char *ls,int n)
{
	if (is == NULL || ls == NULL || n<1)
	{
		return NULL;
	}
	else
		return createIL(is,ls,n);
}

int size(BtNode *ptree)
{
	if (ptree == NULL)
		return 0;
	else
		return size(ptree->leftchild)+size(ptree->rightchild)+1;
}

int depth(BtNode *ptree)
{
	if (ptree == NULL)
		return 0;
	else
		return Max(depth(ptree->leftchild),depth(ptree->rightchild))+1;
}

BtNode *find_value(BtNode *ptree,elemtype x)
{
	if (ptree == NULL || ptree->data == x)
		return ptree;
	else
	{
		BtNode *s = find_value(ptree->leftchild,x);
		if (s == NULL)
		{
			s = find_value(ptree->rightchild,x);
		}
		return s;
	}
}


bool Is_Balance_BinaryTree(BtNode *p)
{
	if (p == NULL)
		return 1;
	int leftdepth = depth(p->leftchild);
	int rightdepth = depth(p->rightchild);
	if (abs(leftdepth - rightdepth) > 1)
		return 0;
	else
		return Is_Balance_BinaryTree(p->leftchild) && Is_Balance_BinaryTree(p->rightchild);
}

//�ǵݹ�Ĺ�����ȱ���
void NiceLevelOrder(BtNode *ptree)
{
	if(ptree == NULL)
		return;
	queue<BtNode *> qu;
	qu.push(ptree);
	while(!qu.empty())
	{
		BtNode *s = qu.front();
		qu.pop();
		cout<<s->data<<" ";
		if (s->leftchild != NULL)
		{
			qu.push(s->leftchild);
		}
		if (s->rightchild != NULL)
		{
			qu.push(s->rightchild);
		}
	}
}

//��ӡ�������ĵ�k��
void print_k(BtNode *p,int k)
{
	if (p != NULL && k == 1)
	{
		cout<<p->data<<" ";
	}
	else if(p != NULL)
	{
		print_k(p->leftchild,k-1);
		print_k(p->rightchild,k-1);
	}
}
void Print_K_Item(BtNode *p,int k)
{
	if (p == NULL || k<1)
		return ;
	print_k(p,k);
}

void LevelOrder(BtNode *p)
{
	if (p == NULL)
		return ;
	int level = depth(p);
	for (int i = 0; i < level; i++)
	{
		Print_K_Item(p,i);
	}
}
//�ǵݹ������������ȱ���
void NicePreOrder(BtNode *p)
{
	if (p == NULL)
		return ;
	stack<BtNode *> treestack;
	treestack.push(p);
	while (!treestack.empty())
	{
		p = treestack.top();
		cout<<p->data<<" ";
		treestack.pop();
		if (p->rightchild != NULL)
		{
			treestack.push(p->rightchild);
		}
		if (p->leftchild != NULL)
		{
			treestack.push(p->leftchild);
		}
	}
}
//�ǵݹ������������ȱ���
//˼��:һֱ������ջ��ֱ������Ϊ�գ���ʼ��ӡ���ڵ㣬Ȼ���Һ�����ջ
//ģ��ݹ����

void NiceInOrder(BtNode *root)
{
	if (root == NULL)
		return ;
	stack<BtNode*> treestack;
	BtNode *p=root;
	while(p!=NULL||!treestack.empty())
	{
		while(p!=NULL)
		{
			treestack.push(p);
			p=p->leftchild;
		}
		p=treestack.top();
		cout<<p->data<<" ";
		treestack.pop();
		p=p->rightchild; 

	}     
}
//�ǵݹ�ĺ���������ȱ���

void NicePastOrder(BtNode *root)
{
	stack<BtNode*> s;
	BtNode *cur; //��ǰ��� 
	BtNode *pre=NULL; //ǰһ�η��ʵĽ�� 
	s.push(root);
	while(!s.empty())
	{
		cur=s.top();
		if((cur->leftchild==NULL&&cur->rightchild==NULL)||
			(pre!=NULL&&(pre==cur->leftchild||pre==cur->rightchild)))
			//�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
		{
			cout<<cur->data<<" "; 
			s.pop();
			pre=cur; 
		}
		else
		{
			if(cur->rightchild!=NULL)
				s.push(cur->rightchild);
			if(cur->leftchild!=NULL)    
				s.push(cur->leftchild);
		}
	}    
}

void NicePastOrder2(BtNode *root)
{
	if (root == NULL)
		return;
	stack<BtNode*> st;
	BtNode *p = root;
	BtNode *tag = NULL;
	while (p != NULL || !st.empty())
	{
		while (p != NULL)
		{
			st.push(p);
			p = p->leftchild;
		}
		p = st.top();
		st.pop();
		//��p���Һ���Ϊ�գ�����p���Һ����ѱ����ʹ������ӡ���ڵ�
		if(p->rightchild == NULL || p->rightchild == tag)
		{
			cout<<p->data<<" ";
			tag = p;
			p = NULL;
		}
		else
		{
			st.push(p);
			p = p->rightchild;
		}

	}
} 

//�ж��Ƿ�Ϊ��������
bool Is_Full_BinaryTree(BtNode *p)
{
	return p == NULL || (p->leftchild == NULL && p->rightchild == NULL)
		||  ( (p->leftchild != NULL && p->rightchild != NULL) && Is_Full_BinaryTree(p->leftchild) 
		&& Is_Full_BinaryTree(p->rightchild) && depth(p->leftchild) == depth(p->rightchild) );
}
//�ж϶������Ƿ�����ȫ����������α��������������������ҽڵ�����С�
//�������еĽ��Ϊ�գ����Ժ�����еĽ�㶼Ϊ�գ���Ϊ��ȫ��������������
bool Is_Comp_BinaryTree(BtNode *root)
{
	BtNode* p=root;
	queue<BtNode*> q;
	int tag=0;
	if(p==NULL) return 1;
	q.push(p);
	while(!q.empty())
	{
		p=q.front(); 
		q.pop(); 
		if(p->leftchild && !tag) 
			q.push(p->leftchild);
		else if(p->leftchild)  
			return 0;
		else 
			tag=1;

		if(p->rightchild && !tag) 
			q.push(p->rightchild);
		else if(p->rightchild)  
			return 0;
		else 
			tag=1;
	}
	return 1;

}

BtNode *find_parent(BtNode *ptr,BtNode *child)
{
	if (ptr == NULL || ptr->leftchild == child || ptr->rightchild == child)
		return ptr;
	else
	{
		BtNode *p = find_parent(ptr->leftchild,child);
		if (p == NULL)
		{
			p = find_parent(ptr->rightchild,child);
		}
		return p;
	}
}
BtNode * FindParent(BtNode *ptr,BtNode *child)
{
	//ptr�����ĸ��ڵ㣬child��һ�����
	if (ptr == NULL || child == NULL || child == ptr)
		return NULL;
	else
		return find_parent(ptr,child);
}

//Ѱ�������������˫��
//BtNode * FindNearParent(BtNode *ptr, BtNode *child1,BtNode *child2)
//{
//if(ptr == NULL || child1 == NULL || child2 == NULL)
//return NULL;


//}
//bool Is_SubTree(BtNode *ptr,BtNode *sub);

void Destroy(BtNode *ptr)
{//��������Ĺ��̣��ȴݻ������ڴݻ��Һ����ڴݻ���
	if (ptr != NULL)
	{
		Destroy(ptr->leftchild);
		Destroy(ptr->rightchild);
		FreeNode(ptr);
	}
}

//�ж��������Ƿ����
bool Is_Equal(BtNode *tree1,BtNode *tree2)
{
	if (tree1 == NULL && tree2 == NULL)
	{
		return 1;
	}
	if (tree1 != NULL && tree2 != NULL)
	{
		if (	tree1->data == tree2->data && Is_Equal(tree1->leftchild,tree2->leftchild) == 1
			&& Is_Equal(tree1->rightchild,tree2->rightchild) == 1)
		{
			return 1;
		}
	}
	return 0;
}

void CopyTree(BtNode* s,BtNode* & d)  
{  
	if(s==NULL) d = NULL;  
	BtNode* temp = new BtNode;
	temp->leftchild = NULL;
	temp->rightchild = NULL;
	temp->data = s->data;  
	if(d==NULL) d = temp;  
	if(s->leftchild) CopyTree(s->leftchild,d->leftchild);  
	if(s->rightchild) CopyTree(s->rightchild,d->rightchild);  
} 
//�������ķǵݹ����
struct stkNode
{
	BtNode *p;
	int popnum;
	stkNode(BtNode *_p,int _popnum = 0):p(_p),popnum(_popnum){}
};
void NicePastOrder3(BtNode *p)
{
	stack<stkNode> st;
	st.push(stkNode(p));
	while (!st.empty())
	{
		stkNode node = st.top();
		st.pop();
		++(node.popnum);
		if (node.popnum == 3)
			cout<<node.p->data<<" ";
		else
		{
			st.push(stkNode(node));
			if (node.popnum == 1 && node.p->leftchild != NULL)
			{
				st.push(stkNode(node.p->leftchild));
			}
			else if (node.popnum == 2 && node.p->rightchild != NULL)
			{
				st.push(stkNode(node.p->rightchild));
			}
		}

	}
}

void main()
{
	char *str = "ABC##DE##F##G#H##";
	//char *str = "ABD##E##CF##G##";
	char *ps = "ABCDEFGH";
	char *is = "CBEDFAGH";
	char *ls = "CEFDBHGA";
	int n = strlen(ps);
	BtNode *root = create_IL(is,ls,n);
	BtNode *p = creat_tree2(str);
	//Print_K_Item(p,3);
	NicePastOrder2(p);
	cout<<endl;
	NicePastOrder3(p);
	//cout<<Is_Full_BinaryTree(p)<<endl;
}

*/