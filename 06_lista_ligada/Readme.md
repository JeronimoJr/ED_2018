## 06_lista_ligada

# Objetivo

- Implementar os métodos de lista encadeada

# O que você fez,como fez e com quem?
Implementei esse trabalho com o meu colega Adan Bueno e ainda ajudei alguns colegas de EC, na criação do método size, a lista é percorrida até o último nó, e a cada nó é incrementado
+1 em uma variável auxiliar que sera retornada pela função, onde ela representa o tamanho da minha lista, fiz esse método tanto interativo como recursivo, já que o senhor não fez em sala.

O método somar é bem parecido com o size, porém, ao invés de incrementar alguma variável,
eu retorno o valor inteiro que está contido no meu nó a cada nó percorrido pela minha função.

No método cortar rabo a lista é percorrida até encontrar o valor de que onde será partida
a minha lista, daquele valor em diante a minha lista não existirá, sera "cortada".

No remover iterativo, crio duas varíáveis, um node que recebe a cabeça da lista, onde percorrera a lista e um nó auxiliar. Crio um laçõ que percorrera a lista, onde pegarei o nó que quero remover, na variável auxiliar guardo o anterior desse nó, já que na remoção, esse nó 
que contém o nó anterior ao que quero remover, apontará para o próximo nó em relação ao nó removido. No geral, ao acabar o laço, poderá haver a remoção no inicio, meio/final da lista e ainda haver a condição de que o valor que quero remover não se encontra na lista, a lista pode está vazia, sem nenhum elemento para remover.

Para inserir ordenado, uso a recursão para percorrer a lista e como caso base, o caso
em que a recursão para, tendo em vista que ela não precisará mais fazer a lista andar, verifico
se o node é nulo, o que quer dizer que chegou ao final da lista ou se o valor que quero inserir 
é menor/maior (dependendo de como vou ordenar), caso seja verdade a condição, é criado um novo node
e se encerra o método.

No push_back recursivo, caminho pela minha lista até chegar ao último valor e insiro o valor que quero colocar na lista, crio um novo nó e façõ ele apontar para nulo, assim determinando ele o último valor da lista.

# O que tem dificuldade ainda?
- No uso de ponteiros e recursão simultaneamente, ainda tenho umas dúvidas 
no funcionamento desses temas. 

# Quanto tempo levou pra fazer a atividade?
- O conteúdo de lista encadeada foi abordado durante 3 semanas,a cada aula 
um método era adicionado para o aluno produzir, levando em conta isso e que
tive de assistir todas as aulas novamente do senhor no you tube, além de que,
antes mesmo de assistir as suas aulas, procurei o conteúdo de lista encadeada 
implementado c, já que estava com dificuldades em entender o que era repassado nas suas aulas, o tempo que levei para finalizar o trabalho foi umas duas semanas e meia, com as horas de estudo
distribuídas ao longo da semana, é uma estimativa, sempre é díficil mensurar o tempo gasto.


