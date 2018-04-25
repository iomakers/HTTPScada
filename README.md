# HTTPScada

# Objetivo

Criar Exemplo e documentar como usar o HTTP Get no HTTPScada

# Aplicação

O Modbus é um protocolo baseado em poll temporizado ao escravo, em que o Modbus requesita num tempo predefinido os dados aos escravo, mas por vezes necessitamos que o dispositivo inicie  e mande os dados em resposta a algum evento. Um grande exemplo dessa situação seria
no caso do sensor de presença. No sensor de presença nós queremos enviar a mudança de estado dele no exato momento que ocorre, isso é conseguido usando o exemplo HTTP GET.

# Exemplo de como atualizar dados do Scada usando HTTP Get

Neste exemplo estamos a enviar um dado float com valor 10 e com nome de dispositivo esp32

O ScadaBR necessita de ser configurado em HTTP receiver, a partir desse momento da configuração ele ficará escutando dados no caminho

"http://MeuCaminho/httpds"

Para enviar um dado com nome "dado" com valor 10 vindo do dispositivo chamado "esp32" realiza-se a seguinte requisição.

"http://MeuCaminho/httpds?__device=esp32&dado=10"
