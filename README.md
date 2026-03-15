# 🤖 Projeto: Robô Seguidor de Linha com Arduino

Seja muito bem-vindo(a)!

Este é o material de apoio para o desenvolvimento do seu **primeiro projeto em eletrônica**.  
A proposta é que você consiga montar e programar seu robô **apenas seguindo este README e utilizando os arquivos do repositório**, mesmo que ainda não tenha muita experiência.

Vamos utilizar como base o material didático fornecido junto com o **Kit Arduino Robótica**, porém faremos algumas melhorias para deixar o projeto mais completo e robusto.

> 💡 Dica: Utilize o material do kit para entender melhor cada componente.  
> Neste guia, o foco será **montagem e programação do projeto**.

---

# 📌 Sobre o Projeto

O projeto consiste na construção de um **robô seguidor de linha**.

Robôs seguidores de linha são dispositivos que se movimentam seguindo um trajeto previamente definido no chão (geralmente uma linha preta sobre fundo branco).

### Como ele funciona:

1. Sensores detectam a diferença de cor no solo.
2. As informações são enviadas para o Arduino.
3. O código interpreta esses dados.
4. O robô decide para onde deve ir (esquerda, direita ou frente).

Neste projeto, além da função de seguir linha, vamos adicionar um **sensor de distância ultrassônico**, permitindo que o robô:

- Detecte obstáculos
- Pare antes de bater
- Fique mais inteligente e seguro

Também adicionaremos **LEDs de indicação de status**, que mostram visualmente o estado do robô durante o funcionamento.

---

# 🧰 Componentes Utilizados

Todos os componentes abaixo estão presentes no kit:

- Placa Arduino Uno R3  
- Cabo USB 2.0 (30cm)  
- Adaptador para bateria 9V  
- Bateria 9V  
- Suporte para 4 pilhas AA  
- 4 pilhas AA  
- Protoboard  
- Jumpers macho-macho  
- Jumpers macho-fêmea  
- 2x Motor DC 3–6V  
- Sensor de Distância Ultrassônico HC-SR04  
- Kit Chassi 2 rodas  
- 2x Módulo Seguidor de Linha TCRT5000  
- Ponte H Dupla L298N  
- 1x LED Verde  
- 1x LED Vermelho  
- 2x Resistores de **330Ω**

Explicação de cada material utilizado:

A Arduino Uno R3 é responsável por realizar o controle principal do sistema. Nela é executado o programa que gerencia os sensores, os motores e os indicadores luminosos do robô. A placa recebe os sinais dos sensores, processa as informações e envia comandos para os atuadores, permitindo que o carrinho se movimente, siga a linha e pare ao detectar obstáculos. 

O cabo USB é utilizado para estabelecer a comunicação entre o computador e a placa Arduino. Por meio dele é possível transferir o código desenvolvido no software de programação para a memória da placa, permitindo que o sistema embarcado execute as instruções definidas no projeto. 

O adaptador de bateria de 9V e consequentemene a bateria de 9V é utilizado para alimentar exclusivamente a placa Arduino. Dessa forma, recebe uma fonte de energia dedicada, garantindo o funcionamento adequado do sistema de controle do robô. 

As quatro pilhas AA através do seu respectivo suporte é responsável por fornecer alimentação para o módulo da ponte H Dupla L298N e, consequentemente, para os motores do carrinho. Essa separação da alimentação ajuda a evitar interferências no funcionamento da placa Arduino causadas pelo consumo dos motores. 

A protoboard é utilizada como plataforma de montagem do circuito eletrônico. Nela são distribuídas as linhas de alimentação (VCC e GND), além das conexões do sensor ultrassônico, dos resistores e dos LEDs utilizados no sistema. 

Os jumpers são utilizados para realizar conexões elétricas entre os diferentes pontos da protoboard e também entre módulos do circuito. Eles permitem a interligação rápida e organizada dos componentes. 

Os motores DC são responsáveis por gerar o movimento do robô. Eles convertem energia elétrica em energia mecânica, fazendo com que as rodas do chassi girem e permitam o deslocamento do robô durante a execução do percurso.

O Módulo Sensor de Distância Ultrassônico HC-SR04 é utilizado para detectar obstáculos à frente do carrinho. Ele funciona emitindo ondas ultrassônicas e medindo o tempo que o sinal leva para retornar após refletir em um objeto. Com base nessa informação, o Arduino consegue calcular a distância e interromper o movimento do robô quando um obstáculo é detectado.

O kit chassi de duas rodas constitui a estrutura mecânica do carrinho. Ele fornece suporte para a fixação dos motores, das rodas, da placa Arduino, das baterias e dos demais componentes eletrônicos do projeto.

O módulo seguidor de linha baseado no sensor TCRT5000 é utilizado parad etectar a linha no percurso. Ele funciona por meio de um sensor infravermelho que identifica diferenças de reflexão entre superfícies claras e escuras, permitindo que o robô reconheça a linha preta e se mantenha no trajeto definido.

A ponte H dupla L298N é responsável por controlar os motores do carrinho. Ele permite que o Arduino controle o sentido de rotação e a velocidade dos motores, possibilitando movimentos como avançar, parar e realizar ajustes de direção durante o percurso.

O LED verde é utilizado como indicador visual de funcionamento normal do carrinho. Ele permanece aceso quando o robô está se movimentando e não há obstáculos detectados pelo sensor ultrassônico.

O LED vermelho funciona como um indicador de alerta. Ele é acionado quando o sensor ultrassônico detecta um objeto à frente do carrinho, indicando que o robô interrompeu seu movimento para evitar uma colisão.

Os resistores de 330 Ω são utilizados em série com cada LED para limitar a corrente elétrica que passa pelos componentes. Essa limitação é necessária para evitar danos aos LEDs e garantir seu funcionamento adequado dentro dos limites de corrente recomendados.

---

# 🔄 Teste de Comunicação (Loopback)

Antes de montar o robô, é importante verificar se a comunicação entre o seu computador e a placa Arduino está funcionando corretamente.

### Passo a passo do teste:

1. Conecte o Arduino ao computador via cabo USB.

2. Para que o teste de loopback funcione, conecte também **os pinos TX e RX do Arduino entre si** (TX no pino RX e RX no pino TX), além de garantir que o Arduino esteja alimentado corretamente (5V e GND).

3. Abra a Arduino IDE e, em seguida, o **Monitor Serial** (ícone de lupa no canto superior direito da IDE ou no menu `Ferramentas > Monitor Serial`).

4. No campo de texto do Monitor Serial (parte superior), digite uma mensagem qualquer e envie.

5. Se a comunicação estiver funcionando, você deverá ver a mesma mensagem aparecer logo abaixo no Monitor Serial, indicando que o Arduino está recebendo e enviando dados corretamente.

![TesteLoopBack](Imagens/TesteLoopback.png)

---

# 🔧 Montagem do Projeto

## 📷 Montagem Original

A montagem sugerida no material do kit utiliza praticamente todos os componentes listados acima.

![EsquematicoEletrogate](Imagens/Esquematico_Eletrogate.png)

---

## 🚀 Nossa Modificação

No projeto original não há o sensor ultrassônico.

Nós iremos adicionar o **HC-SR04**, responsável por detectar obstáculos e impedir que o robô colida com objetos.

### ⚠️ Problema encontrado

Ao tentar adicionar o sensor diretamente no Arduino, percebemos que:

- Não há pinos GND suficientes
- Não há pinos 5V suficientes

Ou seja, não conseguimos simplesmente conectar mais um componente diretamente na placa.

---

## 🧠 Solução: Uso da Protoboard

Para resolver isso, vamos utilizar a **protoboard como distribuidora de energia**.

### Como funcionará:

1. Conecte:
   - 1 fio do GND do Arduino → trilha negativa da protoboard
   - 1 fio do 5V do Arduino → trilha positiva da protoboard

2. A partir da protoboard:
   - Alimente todos os sensores
   - Alimente o módulo L298N (se necessário)
   - Alimente o sensor ultrassônico

Dessa forma:

- Organizamos melhor os fios
- Evitamos sobrecarga nos pinos
- Deixamos o projeto mais organizado e profissional

![EsquematicoTCC](Imagens/ESQUEMATICO_TCC.png)

---

# 💡 Indicadores Visuais com LEDs

Para tornar o comportamento do robô mais fácil de entender durante os testes, adicionamos **dois LEDs indicadores de status**.

Esses LEDs mostram visualmente se o robô está funcionando normalmente ou se detectou um obstáculo.

---

## 🟢 LED Verde — Funcionamento Normal

Quando o robô **não detecta obstáculos**, ele:

- Continua seguindo a linha normalmente
- Mantém o **LED verde aceso**

Isso indica que o robô está operando normalmente.

---

## 🔴 LED Vermelho — Obstáculo Detectado

Quando o **sensor ultrassônico detecta um objeto a menos de 15 cm**, o robô:

- Para imediatamente
- Acende o **LED vermelho**

Isso indica que o robô interrompeu o movimento para **evitar colisão**.

---

# 🔌 Ligação dos LEDs

Cada LED deve ser ligado com um **resistor de 330Ω** para limitar a corrente e evitar danos ao componente.

### LED Verde

Conexão:

- **Pino 12 do Arduino → Resistor 330Ω → Perna longa do LED**
- **Perna curta do LED → GND**

---

### LED Vermelho

Conexão:

- **Pino 13 do Arduino → Resistor 330Ω → Perna longa do LED**
- **Perna curta do LED → GND**

---

### Resumo das conexões

| LED | Pino Arduino | Função |
|----|----|----|
| 🟢 Verde | 12 | Robô em funcionamento |
| 🔴 Vermelho | 13 | Obstáculo detectado |

---

# 📁 Estrutura do Repositório

Este repositório contém:

- Código-fonte do Arduino
- Imagens dos esquemas de ligação
- Este guia passo a passo

---

# 🪜 Passo a Passo

Siga esta ordem:

1. Monte o chassi
2. Instale os motores
3. Fixe os sensores
4. Faça as conexões elétricas conforme o esquema modificado
5. Conecte o Arduino ao computador via USB
6. Faça o upload do código
7. Teste o funcionamento

---

# ⚡ Como Funciona o Robô

## 🔎 Seguidor de Linha

Os sensores TCRT5000 detectam a linha no chão.

Aprenda sobre o sensor aqui: https://www.youtube.com/watch?v=dAQYf4zdnks
- Linha detectada → envia sinal ao Arduino  
- Fora da linha → Arduino corrige a direção  

---

## 📡 Sensor Ultrassônico

O HC-SR04 mede a distância até um objeto à frente.

Aprenda sobre o sensor aqui: https://www.youtube.com/watch?v=TX62dkfrb34

Se a distância for menor que o valor definido no código:

- O robô para
- O **LED vermelho acende**
- Evita colisão

Quando não há obstáculos:

- O robô continua seguindo a linha
- O **LED verde permanece aceso**

---

# 🎯 Objetivo Final

Ao final deste projeto, você terá:

- ✔ Um robô seguidor de linha funcional  
- ✔ Sistema de parada por obstáculo  
- ✔ Indicadores visuais de status (LEDs)  
- ✔ Conhecimento básico de:
  - Sensores
  - Controle de motores
  - Programação em Arduino
  - Distribuição de energia com protoboard  

---

# 💡 Dicas Importantes

- Sempre revise as conexões antes de ligar a bateria.
- Teste primeiro alimentando pelo USB.
- Se algo não funcionar, revise:
  - Ligações GND
  - Ligações 5V
  - Pinos definidos no código

---

# 🚀 Próximo Passo

Agora que você já entendeu a estrutura do projeto:

➡️ Monte o robô  
➡️ Configure o ambiente Arduino  
➡️ Faça o upload do código  
➡️ Realize os testes  

Se seguir o passo a passo com atenção, você conseguirá montar tudo mesmo sendo iniciante.

Bom projeto!
