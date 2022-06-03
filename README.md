# Proyecto_EDnoL

UEA: Estruturas de Datos No Lineales.

Resumen.

Problema: Tener un control de seguridad en el acceso al sistema de una Empresa X, el cual debe ser creado de manera que cada trabajador
(usuario con acceso) pueda autenticarse y entrar al sistema.

Solución: Cada trabajador cuenta con un “username” y un “password”, entonces el sistema deberá ser capaz de pedir a cada usuario una autenticación
usando estos dos atributos para buscarlos y posterior darles acceso al sistema.

Resultados: Los resultados que se obtuvieron fueron exitosos ya que el problema fue solucionado manera eficiente.

Introducción.

Se considero el organizar una colección de identificadores de usuario y sus palabras clave. Cada vez que un usuario accede al sistema de la Empresa X,
será introduciendo su “username” y “password”, entonces el sistema debe comprobar la validez de ambos para verificar la legitimidad del usuario. Dicha
autenticación podría realizarse numerosas ocasiones cada día, por lo que es necesario estructurar la información de forma que se pueda encontrar a cada
usuario rápidamente y además debe ser una estructura dinámica ya que pueden irse añadiendo mas trabajadores (usuarios) al sistema.

Objetivos.

Uno de los objetivos del problema es la información del usuario (“username” y “password”) por lo que se pueden plantear los siguientes objetivos.
Impedir el acceso no autorizado a los sistemas de información, trabajo y base de datos de la Empresa X.
Implementar seguridad en los accesos a los usuarios por medio de técnicas de autenticación y autorización.
Concientizar a los usuarios respecto a la responsabilidad frente a la autenticación de contraseñas y equipos.
Garantizar la seguridad de la información.

Desarrollo.

Lo primero fue crear un proyecto en C++.
Agregue la implementación del archivo ABB.h.
Cree un archivo “usuarios.txt” para simular la base de datos de la empresa donde se tienen registrados a los usuarios.
En el archivo main.cpp cree una clase llamada Sistema la cual tiene un único atributo que es un ABB de strings y acceso() como única función.

En el método acceso() de la clase Sistema, ubicada en el archivo main.cpp se realizo lo siguiente:
Se da lectura al archivo “usuarios.txt”.
Por cada línea que se lee del archivo se obtiene a un usuario. Para este proyecto se simulo que la Empresa X almacena a sus usuarios usando la siguiente estructura: “username”-”password”, ejemplo: Giovanny-12345.
A la par de que se va leyendo cada línea (obteniendo a cada usuario) se va insertando en el ABB, usando el propio método de insertar() de la clase ABB.h.
Posteriormente en un ciclo pido introducir el username, el cual si se introduce “salir” terminara la ejecución del programa. De no ser así, si el usuario introduce su “username”, en seguida se pide al usuario que introduzca su “password”.
Dentro de un condicional se verifica la validez de ambos. Usando el método buscar() propio de la clase ABB.h, se busca al usuario en los insertados en el ABB creado anteriormente.
De ser ambos correctos aparecerá en pantalla un mensaje de bienvenida diciendo que se permitió el acceso y de no ser así aparecerá un mensaje de advertencia diciendo que no se permitió el acceso.
