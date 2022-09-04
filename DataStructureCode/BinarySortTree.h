#include<iostream>
typedef struct BiTNode
{
	int data;
	int bf;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

int SearchBST(BiTree T, int key, BiTree f, BiTree* p)
{
	if (!T)
	{
		*p = f;
		return 0;
	}
	else if (key == T->data)
	{
		*p = T;
		return 1;
	}
	else if (key <= T->data)
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else
	{
		return SearchBST(T->rchild, key, T, p);
	}
}

int InsertBST(BiTree* T, int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;

		if (!p)
		{
			*T = s;
		}
		else if (key < p->data)
		{
			p->lchild = s;
		}
		else if (key > p->data)
		{
			p->rchild = s;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int DeleteBST(BiTree* T, int key)
{
	if (!*T)
	{
		return false;
	}
	else
	{
		if (key == (*T)->data)
		{
			return Delete(T);
		}
		else if (key <= (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

int Delete(BiTree* p)
{
	BiTree q, s;
	if ((*p)->lchild = NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else if ((*p)->rchild = NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else
	{
		q = *p;
		s = (*p)->lchild;
		while (s)
		{
			q = s;
			s = s->rchild;
			
		}
		(*p)->data = s->data;
		if (q != *p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		free(s);
	}
	return 1;
}

void R_Rotate(BiTree* p)
{
	BiTree L;
	L = (*p)->lchild;
	(*p)->lchild = L->rchild;
	L->rchild = *p;
	*p = L;
}

void L_Rotate(BiTree* p)
{
	BiTree R;
	R = (*p)->rchild;
	(*p)->rchild = R->lchild;
	R->lchild = *p;
	*p = R;
}