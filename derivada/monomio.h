#ifndef MONOMIO_H
#define MONOMIO_H

typedef struct monomio MON;

MON *monomio_criar(void);
void monomio_apagar(MON *m);
void monomio_ler(MON *m);
long long monomio_coeficiente(MON *m);
long long monomio_grau(MON *m);
MON *monomio_definir(long long coef, long long grau);
long long monomio_resolver(MON *m, long long x);
long long monomio_derivada(MON *m, long long x);

#endif