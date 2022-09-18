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

int Delete(BiTree* p);

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

#define LH +1
#define EH 0
#define RH -1

void LeftBalance(BiTree* T)
{
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf)
	{
		case LH:
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH:
			Lr = L->rchild;
			switch (Lr->bf)
			{
			case LH:
				(*T)->bf = RH;
				L->bf = EH;
				break;
			case EH:
				(*T)->bf = L->bf = EH;
				break;
			case RH:
				(*T)->bf = EH;
				L->bf = LH;
				break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);
			R_Rotate(T);
			break;
	}
}

void RightBalance(BiTree* T)
{
	BiTree R, Rl;
	R = (*T)->rchild;
	switch (R->bf)
	{
	case RH:
		(*T)->bf = R->bf = EH;
		L_Rotate(T);
		break;
	case LH:
		Rl = R->lchild;
		switch (Rl->bf)
		{
		case RH:
			(*T)->bf = LH;
			R->bf = EH;
			break;
		case EH:
			(*T)->bf = R->bf = EH;
			break;
		case LH:
			(*T)->bf = EH;
			R->bf = RH;
			break;
		}
		Rl->bf = EH;
		R_Rotate(&(*T)->rchild);
		L_Rotate(T);
		break;
	}
}

int InsertAVL(BiTree* T, int e, int* taller)
{
	if (!*T)
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = 1;
	}
	else
	{
		if (e == (*T)->data)
		{
			*taller = 0;
			return 0;
		}
		if (e < (*T)->data)
		{
			if (!InsertAVL(&(*T)->lchild, e, taller))
				return 0;
			if (taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					LeftBalance(T);
					*taller = 0;
					break;
				case EH:
					(*T)->bf = LH;
					*taller = 1;
					break;
				case RH:
					(*T)->bf = EH;
					*taller = 0;
					break;
				}
			}
		}
		else
		{
			if (!InsertAVL(&(*T)->rchild, e, taller))
				return 0;
			if (*taller)
			{
				switch ((*T)->bf)
				{
				case LH:
					(*T)->bf = EH;
					*taller = 0;
					break;
				case EH:
					(*T)->bf = RH;
					*taller = 1;
					break;
				case RH:
					RightBalance(T);
					*taller = 0;
					break;
				}
			}
		}
	}
	return 1;
}
