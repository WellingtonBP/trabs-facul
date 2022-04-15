import math

def decimalParaBase(numero, base):
    if base != 2 and base != 8 and base != 16:
      print('Não é possível converter para essa base!')
      return
    result = []
    while numero > 0:
      resto = numero % base
      result.append(resto)
      print(f'{numero} / {base} -> {resto}')
      numero = math.floor(numero/base)
    else:
      result = result if base != 16 else list(map(lambda n: {n:n, 10:'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F'}[n], result))
      resultStr = ''.join(map(str, result[::-1]))
      print(f'O número informado na base {base} é igual a {resultStr}')

numero = int(input('Digite o numero decimal a ser convertido: '))
base = int(input('Digite a base: '))
decimalParaBase(numero, base)
