<div><img src="https://game.42sp.org.br/static/assets/images/42-saopaulo.png" height=80>
<img src="https://game.42sp.org.br/static/assets/achievements/so_longe.png" align="right" height=100></div>

<br>

# SO_LONG
<span style="color:red; font-weight:bold">Não entregue devido a mudanças no projeto em (19/09/2022)</span><br>
consultar [SO_LONG_V2](https://github.com/leogremes/42SP_so_long_v2) para ver o que foi entregue

## Sobre
O objetivo deste projeto era desenvolver um jogo simples onde um personagem deve coletar alguns itens pelo
mapa e ir para a saída. O jogo deve atender uma série de especificações e devemos utilizar a <b>minilibx</b>
que é a biblioteca que permite criar uma janela e interagir com ela. Além disso poderíamos utilizar
a nossa <b>[LIBFT](https://github.com/leogremes/42SP_libft)</b> e o nosso
<b>[FT_PRINTF](https://github.com/leogremes/42SP_ft_printf)</b>.

## Desenvolvimento
Mais uma vez eu optei por não utilizar a libft inteira, eu reescrevi do zero só as funções que eu
precisei utilizar e também não precisei de utilizar o ft_printf.

A primeira coisa que o programa faz é verificar os argumentos passados na hora de executar.
Logo após ele verifica se o argumento corresponde a um arquivo ".ber" (como definido no escopo do projeto)
e tenta abri-lo. Após abrir o arquivo, o programa vai ler cada caractére, somando os elementos encontrados
e formando uma <i>string</i>. Se os requisitos de elementos tiverem sido cumpridos (pelo menos uma saída,
uma posição inicial e um coletável), essa <i>string</i> será transformada em uma matriz, que será o mapa.

Com o mapa formado, o programa vai verificar se ele é retangular e se é cercado por paredes.
Passando nessas verificações o programa checa se não há caracteres inválidos. Vale ressaltar
que, caso qualquer uma das verificações apresentem erro, as memórias são liberadas e o programa
é abortado

Passando toda a fase das verificações, o programa inicia a minilibx, cria a janela e aloca o espaço
dos <i>sprites</i>. Para o jogo rodar temos uma função de renderizar a tela que percorre todo o mapa,
lendo cada elemento, busca a imagem e insere na posição correspondente, além de atualizar o contador
de movimentos no topo da janela. Temos também uma função para interagir com as teclas pressionadas
(movendo o jogador ou fechando a janela) e uma função para monitorar o clique no "X" da janela.

As animações dos sprites e os inimigos são implementados através de <b>listas encadeadas</b>. 
Existe um contador sendo incrementado sempre que o programa desenha a tela, e quando o contador atinge
o limite (definido no cabeçalho) é disparada a função que movimenta os inimigos (percorrendo a lista)
e/ou a função que troca a animação dos sprites (apontando pro próximo nó da lista ou voltando ao primeiro).

Quando o jogo termina (ou quando é interrompido) é impressa uma mensagem no terminal e o programa é encerrado.

## Aprendizado
Este projeto não apresentou muito conteúdo novo, mas os principais aprendizados foram:
- função <b><i>exit</i></b> (encerra o programa em qualquer momento).
- funções <i><b>perror</b></i> e <i><b>strerror</b></i> (Não usei, mas pesquisei sobre elas pois estavam no escopo).
- <b>criação e manipulação de janelas</b> (através da minilibx, mas acredito que seja uma boa base).

Uma dificuldade que tive que superar é que os projetos começam a ficar extensos e complexos, também tive a
oportunidade de explorar bastante o uso das <b><i>structs</i></b> e das <b>listas encadeadas</b>.

## Impressões Pesoais
Este é o quinto projeto da 42 e até agora foi o mais divertido de fazer apesar de ter sido um projeto
considerávelmente maior que os já feitos até aqui.
Ver o resultado do projeto, por mais simples que seja, é muito satisfatório e traz a sensação de que
valeu a pena.