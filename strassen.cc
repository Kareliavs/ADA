#include<bits/stdc++.h>
#define DATATYPE_FORMAT "%4.2g"
#define M 3
#define N (1<<M) //4
using namespace std;

typedef double datatype;

typedef datatype mat[N][N];

typedef struct
{
        int ra, rb, ca, cb;
} corners;
// A[ra..rb]
//  [ca..cb]

// set A[a] = k
void set_a(mat A, corners a, datatype k)/*COMO quiere llenarla con k*/
{
    int i, j;
    for (i = a.ra; i < a.rb; i++)
        for (j = a.ca; j < a.cb; j++)
            A[i][j] = k;
}

void randk(mat A, corners a, int h)/*llena random menor que h */
{
    int i, j;
    for (i = a.ra; i < a.rb; i++)
        for (j = a.ca; j < a.cb; j++)
            A[i][j] = rand()%h;
}

// Print A[a]
void print(mat A, corners a, char *name)
{
    int i, j;
    cout<<name<<"= {"<<endl;
    for (i = a.ra; i < a.rb; i++)
    {
        for (j = a.ca; j < a.cb; j++)
            printf(DATATYPE_FORMAT ", ", A[i][j]);
        cout<<endl;
    }
    cout<<"}"<<endl;
}

// C[c] = A[a] + B[b]
void add(mat A, mat B, mat C, corners a, corners b, corners c)
{
    int rd = a.rb - a.ra;
    int cd = a.cb - a.ca;
    int i, j;
    for (i = 0; i < rd; i++)
    {
        for (j = 0; j < cd; j++)
        {
            C[i + c.ra][j + c.ca] = A[i + a.ra][j + a.ca] + B[i + b.ra][j+ b.ca];
        }
    }
}

// C[c] = A[a] - B[b]
void sub(mat A, mat B, mat C, corners a, corners b, corners c)
{
    int rd = a.rb - a.ra;
    int cd = a.cb - a.ca;
    int i, j;
    for (i = 0; i < rd; i++)
    {
        for (j = 0; j < cd; j++)
        {
            C[i + c.ra][j + c.ca] = A[i + a.ra][j + a.ca] - B[i + b.ra][j+ b.ca];
        }
    }
}

// top/bottom , left/right.
void encuentra_corner(corners a, int i, int j, corners *b)
{
    int rm = a.ra + (a.rb - a.ra) / 2;//inicio+ longitud/2
    int cm = a.ca + (a.cb - a.ca) / 2;
    *b = a;
    if (i == 0)
        b->rb = rm; // top rows
    else
        b->ra = rm; // bot rows
    if (j == 0)
        b->cb = cm; // left cols
    else
        b->ca = cm; // right cols
}

// Multiplica: A[a] * B[b] => C[c], recursivo.
void mul(mat A, mat B, mat C, corners a, corners b, corners c)
{
    corners aii[2][2], bii[2][2], cii[2][2], p;
    mat P[7], S, T;
    int i, j, m, n, k;

    // Check: A[m n] * B[n k] = C[m k]
    m = a.rb - a.ra;   //longitud horizontal                                                                                                                 assert(m==(c.rb-c.ra));
    n = a.cb - a.ca;   //longitud vertical                                                                                                                 assert(n==(b.rb-b.ra));
    k = b.cb - b.ca;   //longitud vertical b                                                                                                                 assert(k==(c.cb-c.ca));
                                                                                                                                        assert(m>0);

    if (n == 1)///caso base longitud 1
    {
        C[c.ra][c.ca] += A[a.ra][a.ca] * B[b.ra][b.ca];
        return;
    }

    //  A00 A01   B00 B01   C00 C01
    //  A10 A11   B10 B11   C10 C11
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            encuentra_corner(a, i, j, &aii[i][j]);
            encuentra_corner(b, i, j, &bii[i][j]);
            encuentra_corner(c, i, j, &cii[i][j]);
        }
    }

    p.ra = p.ca = 0;
    p.rb = p.cb = m / 2;

    for (i = 0; i < sizeof(P)/sizeof(P[0]); i++)
        set_a(P[i], p, 0);


        /*
        p0=a(f-h)       p1=(a+b)h
        p2=(c+d)e       p3=d(g-e)
        p4=(a+d)(e+h)   p5=(b-d)(g+h)
        p6=(a-c)(e+f)
        */

    // A00 * (B01 - B11) = A00 * T = P2
    sub(B, B, T, bii[0][1], bii[1][1], p);//a*(f-h)
    mul(A, T, P[1-1], aii[0][0], p, p);

    // (A00 + A01) * B11 = S * B11 = P4
    add(A, A, S, aii[0][0], aii[0][1], p);//(a+b)*h
    mul(S, B, P[2-1], p, bii[1][1], p);

    // (A10 + A11) * B00 = S * B00 = P1
    add(A, A, S, aii[1][0], aii[1][1], p);//(c+d)*e
    mul(S, B, P[3-1], p, bii[0][0], p);

    // A11 * (B10 - B00) = A11 * T = P3
    sub(B, B, T, bii[1][0], bii[0][0], p);//d*(g-e)
    mul(A, T, P[4-1], aii[1][1], p, p);

    // (A00 + A11) * (B00+B11) = S * T = P0
    add(A, A, S, aii[0][0], aii[1][1], p);//(a+d)*(e+h)
    add(B, B, T, bii[0][0], bii[1][1], p);
    mul(S, T, P[5-1], p, p, p);

    // (A01 - A11) * (B10 + B11) = S * T = P6
    sub(A, A, S, aii[0][1], aii[1][1], p);//(b-d)*(g+h)
    add(B, B, T, bii[1][0], bii[1][1], p);
    mul(S, T, P[6-1], p, p, p);

    // (A00-A10) * (B00 + B01) = S * T = P5
    sub(A, A, S, aii[0][0], aii[1][0], p);//(a-c)*(e+f)
    add(B, B, T, bii[0][0], bii[0][1], p);
    mul(S, T, P[7-1], p, p, p);

/*--------------C FINAL---------------*/
    // P5 + P4 - P2 + P6 = C00
    add(P[5-1], P[4-1], S, p, p, p);//()
    sub(S, P[2-1], T, p, p, p);
    add(T, P[6-1], C, p, p, cii[0][0]);

    // P1 + P2 = C01
    add(P[1-1], P[2-1], C, p, p, cii[0][1]);

    // P3 + P4 = C10
    add(P[3-1], P[4-1], C, p, p, cii[1][0]);

    // P1 + P5 - P3 - P7 = C11
    add(P[1-1], P[5-1], S, p, p, p);
    sub(S, P[3-1], T, p, p, p);
    sub(T, P[7-1], C, p, p, cii[1][1]);

}
int main()
{
    mat A, B, C;

    corners ai = { 0, N, 0, N };
    corners bi = { 0, N, 0, N };
    corners ci = { 0, N, 0, N };
    srand(time(0));
    randk(A, ai,7);
    randk(B, bi, 2);
    print(A, ai, "A");
    print(B, bi, "B");
    set_a(C, ci, 0);
    // add(A,B,C, ai, bi, ci);
    mul(A, B, C, ai, bi, ci);
    print(C, ci, "C");
    return 0;
}
