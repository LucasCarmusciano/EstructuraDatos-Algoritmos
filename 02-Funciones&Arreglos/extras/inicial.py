totalPares = 0
sumaPares = 0
totalDiv3 = 0
promedioPares = 0

num = int(input("Ingrese un número entero mayor a cero (o 0 para terminar): "))
while num>0:
    if num%2==0:
        totalPares += 1
        sumaPares += num
    if num%3==0:
        totalDiv3 += 1
    num = int(input("Ingrese un número entero mayor a cero (o 0 para terminar): "))

if totalPares!=0:
    promedioPares = sumaPares/totalPares

print("El promedio de numeros pares es: ", promedioPares)
print("La cantidad de numeros multiplos de 3 es: ", totalDiv3)