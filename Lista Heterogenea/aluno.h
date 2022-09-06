#ifndef aluno_h
#define aluno_h


typedef struct aluno Aluno;

Aluno * InsereAluno(char * nome);
char * RetornaNome(Aluno * aluno);
int RetornaMatricula(Aluno * aluno);
void PrintarAluno(Aluno *  aluno);
void LiberarAluno(Aluno * aluno);


#endif 