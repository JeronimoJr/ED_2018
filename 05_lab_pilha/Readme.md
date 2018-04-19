## 05_lab_pilha

# Objetivo

- Implementar o algoritmo da construção do labirinto utilizando PILHA

# O que você fez,como fez e com quem?
	Implementei o algorítmo do labirinto com PILHA junto com o Adan Bueno de EC.
O código foi bem parecido com o de achar o caminho entre dois pontos feito em
sala, ocorrendo variações pontuais na construção do código.
	Criei um "vector<Par> &pilha" no parâmetro da função de criação do
labirinto, inicializo um ponto com ABERTO, ou seja, eu furo ele, utilizo um
laço para furar os demais pontos que podem ser furados para a construção do
labirinto, crio um vector de "vizinhos_fechados", para pegar os pontos que
podem ser furados, obedecendo a regra de ter no máximo um lado aberto, 
dado isso ,chamo a função counOpen para verificar essa regra, seleciono
 os pontos que podem ser furados e colocados em vizinhos_fechados, 
caso não nenhum ponto esteja em vizinhos_fechados utilizo pop.back() na pilha, 
se não, escolho aleatoriamente um ponto que está armazenado em vizinhos_fechados 
e furo ele. A ideia do algoritmo é basicamente essa.

# O que tem dificuldade ainda?
Tenho dificuldade na abstração do código.

# Quanto tempo levou pra fazer a atividade?
Levando em consideração que tive de assistir todas as aulas sobre o assunto e 
ainda utilizei da monitoria para realizar o inicio do código, gastei umas 7 a 8
horas de estudo.

