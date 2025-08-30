# 🚢 Batalha Naval em C

Este projeto implementa uma versão inicial do jogo **Batalha Naval** em linguagem **C**.  
O programa cria um tabuleiro de 10x10 e posiciona navios de tamanho 3 de forma validada.

---

## 📌 Funcionalidades Implementadas

1. **Tabuleiro 10x10**
   - Representado por uma matriz bidimensional (`int tabuleiro[10][10]`).
   - `0` representa água.
   - `3` representa partes de navios.

2. **Funções Principais**
   - `posicionamentoValido()`:  
     Verifica se um navio pode ser posicionado nas coordenadas fornecidas.  
     Garante que esteja dentro dos limites do tabuleiro e que não haja sobreposição com outros navios.
   - `posicionarNavio()`:  
     Posiciona um navio no tabuleiro, de forma **horizontal** ou **vertical**, após a validação.

3. **Exibição do Tabuleiro**
   - O tabuleiro é exibido no console de forma organizada, com coordenadas e conteúdos de cada posição.

4. **Exemplo de Posicionamento**
   - Um navio horizontal na **linha 2**, começando na **coluna 3**.
   - Um navio vertical na **coluna 7**, começando na **linha 5**.

---

## ✅ Requisitos Atendidos

- Tabuleiro fixo de **10x10**.
- Navios de tamanho fixo de **3 posições**.
- Validação de limites do tabuleiro.
- Verificação de sobreposição de navios.
- Exibição clara do tabuleiro no console.

---

## 📖 Próximos Passos

Este projeto serve como ponto de partida para a evolução do jogo. Possíveis melhorias futuras:

- Implementar ataques e registrar **acertos/erros**.
- Adicionar diferentes tamanhos de navios.
- Criar um sistema de turnos para **dois jogadores**.
- Interface gráfica para melhor visualização do tabuleiro.

---

## 🚀 Como Executar

1. Compile o código:
2. 
   ```bash
   gcc batalhaNaval.c -o batalhaNaval
