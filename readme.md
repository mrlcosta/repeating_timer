# Temporizador Periódico - Semáforo com LEDs RGB

Este projeto implementa um semáforo utilizando LEDs RGB, controlado por um temporizador periódico com a função `add_repeating_timer_ms()` do Pico SDK. O semáforo alterna entre as cores vermelha, amarela e verde, com cada sinal ficando ativo por 3 segundos.

## Requisitos

1. **Início do semáforo:**
   - O semáforo inicia com o LED vermelho aceso, conforme o padrão de sinais de trânsito.
   - Após o vermelho, o semáforo alterna para o sinal verde e depois para o sinal amarelo. E repete novamente.

2. **Temporização:**
   - O temporizador é configurado para acionar a mudança de estado dos LEDs a cada 3 segundos (3000 ms).
   
3. **Função de Call-back:**
   - A mudança de estado dos LEDs é implementada dentro da função de call-back do temporizador. A lógica de alternância entre os sinais do semáforo é tratada na função `repeating_timer_callback()`, que é acionada a cada 3 segundos.
   
4. **Rotina Principal:**
   - A rotina principal do programa, executada dentro de um loop `while`, imprime uma mensagem na porta serial a cada 1 segundo (1000 ms), oferecendo informações sobre o estado do semáforo ou do temporizador.
   
5. **Hardware:**
   - O experimento é desenvolvido utilizando a ferramenta BitDogLab e o LED RGB conectado aos pinos GPIO 11, 12 e 13 do microcontrolador.

## Arquitetura do Projeto

- **Função `repeating_timer_callback()`:**  
   Esta função é chamada pelo temporizador a cada 3 segundos para alternar a cor do semáforo entre vermelho, amarelo e verde.
   
- **LEDs RGB:**
   - **GPIO 11:** Controla o LED verde.
   - **GPIO 12:** Controla o LED amarelo.
   - **GPIO 13:** Controla o LED vermelho.
   
- **Temporizador:**  
   Utiliza a função `add_repeating_timer_ms()` para criar o temporizador que chama a função de call-back a cada 3000 ms.

## Como Executar

1. **Configuração do Hardware:**
   - Conecte o LED RGB aos pinos GPIO 11, 12 e 13.
   - Certifique-se de que os LEDs estejam corretamente conectados com a configuração de corrente adequada (pode ser necessário usar resistores para limitar a corrente).
   
2. **Carregar o código:**
   - Compile e carregue o código no microcontrolador com o Pico SDK.

3. **Monitor Serial:**
   - Abra o monitor serial para acompanhar as mensagens de depuração ou o estado do semáforo a cada segundo.

