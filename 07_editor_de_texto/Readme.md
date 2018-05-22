## 07_editor_de_texto

# Objetivo

- Implementar um editor de texto simplificado

# O que você fez,como fez e com quem?
 Fiz apenas a parte I do trabalho que é a de desenvolver a funcionalidade do cursor.
No tratamento do “Right” usei um if para determinar um limite para o meu cursor a direita,
o "Right"move o cursor para direita, condição utilizada:

- if(amb.cursor != amb.texto.end())

De forma análoga para o "Left" (move o cursor para esquerda), uso uma condição para o meu
cursor não extrapolar os limites a esquerda, condição utilizada:

- if(amb.cursor != amb.texto.begin())

No "Delete" apago o caractere da frente do meu cursor, caso houver, e faço ele andar para frente.

- if(amb.cursor != amb.texto.end()) amb.texto.erase(amb.cursor++);

No "Backspace" apago um caractere atrás do meu cursor.

- if(amb.cursor != amb.texto.begin()) amb.texto.erase(amb.cursor++, amb.cursor--);

Nos métodos "Delete" e "Backspace" utilizei a função "erase", que tanto pode remover uma posiçao
de uma lista quanto uma posiçao de determinado intervalo, como é feito no delete e backspace
respectivamente.

Fiz o trabalho sózinho.


# O que tem dificuldade ainda?
 Manipulação do iterador

# Quanto tempo levou pra fazer a atividade?
 Levei um dia.
