'''
Ayla, Kelly, Marina
arq = a^3n b^n c^n+1
arq2 = a^n b^n
arq3 = a^2n b^m c^2m+1 d^n
arq4 = a^n b^2n
arq5 = a^n b^n+1
arq6 = a^2n b^n
arq7 = a^n b^m m>=n
arq8 = a^n b^n c^m d^m
'''
pilha = ['I']


def is_empty():
    return pilha == []


def empilha(item):
    pilha.append(item)


def desempilha():
  if is_empty():
    return -1
  else: 
    pilha.pop(-1)
    return pilha
  
def peek():
  if is_empty():
    return -1
  else:  
    return pilha[-1]

estadoI = '1'

regras = []
arq = open('arq4.txt', 'r', encoding="utf8")
for linha in arq:
  regras.append(linha)

cadeia = input('Entre com a cadeia:')

for letra in cadeia:
  for regra in regras:
    estado = regra[1]
    lido = regra[3]
    topo = regra[5]
    novoEstado = regra[9]
    muda = regra[11:(len(regra) - 2)]
    
    if (estado == estadoI) and (lido == letra) and (muda != 'E') and (topo == peek()):
      print(letra)
      print(regra)
      pilha = desempilha()
      for qtd in muda[::-1]:
        empilha(qtd)
      estadoI = novoEstado
      print(pilha)
      break
    elif (estado == estadoI) and (lido == letra) and (muda == 'E') and (topo == peek()):
      print(regra)
      pilha = desempilha()
      estadoI = novoEstado
      print(pilha)
      break

print(is_empty())
