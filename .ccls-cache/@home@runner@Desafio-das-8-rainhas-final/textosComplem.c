//NÃO FAZ PARTE DO CODIGOOOOO, MAS VAI AJUDAR DEPOIS NA EXPLICAÇÃO DE QUANDO FOR FAZER O TEXTO

/*A técnica utilizada para encontrar a solução do problema das 8 rainhas é a busca em profundidade, que é um algoritmo de backtracking.

A busca em profundidade começa com um tabuleiro vazio e tenta colocar uma rainha em cada coluna, uma de cada vez, verificando se é possível colocar uma rainha em uma dada coluna sem conflitar com as rainhas já colocadas no tabuleiro. Se for possível, a busca continua recursivamente para a próxima coluna, até que todas as colunas tenham sido preenchidas com sucesso.

Se em algum momento não for possível colocar uma rainha em uma coluna sem conflitar com as rainhas já colocadas, a busca retorna à coluna anterior e tenta colocar a rainha em outra posição. Se não for possível colocar a rainha em nenhuma posição da coluna anterior, a busca retorna à coluna anterior a esta e assim por diante, até que seja encontrada uma solução ou que todas as possibilidades tenham sido exploradas.

A técnica de backtracking é uma estratégia geral de busca que consiste em explorar todas as possibilidades do problema de forma sistemática, mas descartando as opções que não levam a uma solução válida. No caso das 8 rainhas, a busca em profundidade é uma forma eficiente de encontrar todas as soluções possíveis, já que o número de soluções é relativamente pequeno.*/



//-------------------------//--------------------------------------

/*É importante notar que essa função é uma implementação do algoritmo de backtracking para resolver o problema das N Rainhas. A ideia é posicionar uma rainha em cada linha do tabuleiro, e para cada linha, tentar posicionar uma rainha em cada coluna. Se uma rainha não puder ser posicionada em uma coluna, a função volta para a linha anterior e tenta outra coluna. Se todas as colunas de todas as linhas forem verificadas e nenhuma solução for encontrada, a função volta para a linha anterior e tenta outra coluna novamente. Esse processo é repetido até que todas as soluções possíveis sejam encontradas.*/