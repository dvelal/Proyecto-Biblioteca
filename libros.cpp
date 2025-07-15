#include"libros.h"

// Permite usar la lista de inicialización {} para llenar los campos de una estructura en el mismo orden en que fueron definidos.
void cargarLibrosPredefinidos(Libro libros[], int &contador) {

    // Matematica - Calculo
    libros[contador++] = {"Calculo", "James Stewart", 8, 2020, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo I", "Luis Arana", 2, 2019, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo Diferencial", "Julio Rios", 3, 2016, "Matematica", "Calculo"};
    libros[contador++] = {"Calculo Integral", "Pedro Poma", 4, 2018, "Matematica", "Calculo"};
    libros[contador++] = {"Curso de Calculo", "Carlos Zavala", 1, 2015, "Matematica", "Calculo"};

    // Matematica - Algebra
    libros[contador++] = {"Algebra Lineal", "David Lay", 5, 2016, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra I", "Luis Arana", 3, 2020, "Matematica", "Algebra"};
    libros[contador++] = {"Problemas de Algebra", "Walter Apaza", 2, 2019, "Matematica", "Algebra"};
    libros[contador++] = {"Algebra Elemental", "Cesar Delgado", 1, 2015, "Matematica", "Algebra"};
    libros[contador++] = {"Curso de Algebra", "Pedro Poma", 4, 2017, "Matematica", "Algebra"};

    // Matematica - Geometria
    libros[contador++] = {"Geometria Euclidiana", "Fernando Cardenas", 1, 2015, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria Analitica", "Maria Romero", 2, 2017, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria Plana", "Luis Suarez", 3, 2016, "Matematica", "Geometria"};
    libros[contador++] = {"Geometria en el Espacio", "Pedro Diaz", 2, 2014, "Matematica", "Geometria"};
    libros[contador++] = {"Figuras Geometricas", "Juan Vega", 1, 2013, "Matematica", "Geometria"};

    // Matematica - Aritmetica
    libros[contador++] = {"Aritmetica I", "Luis Arana", 2, 2015, "Matematica", "Aritmetica"};
    libros[contador++] = {"Aritmetica Basica", "Carmen Flores", 1, 2016, "Matematica", "Aritmetica"};
    libros[contador++] = {"Curso de Aritmetica", "Pedro Poma", 2, 2017, "Matematica", "Aritmetica"};
    libros[contador++] = {"Aritmetica para Pre", "Walter Apaza", 1, 2014, "Matematica", "Aritmetica"};
    libros[contador++] = {"Teoria de Numeros", "Carlos Rojas", 2, 2020, "Matematica", "Aritmetica"};

    // Matematica - Estadistica
    libros[contador++] = {"Estadistica Matematica", "John Freund", 8, 2010, "Matematica", "Estadistica"};
    libros[contador++] = {"Probabilidad y Estadistica", "Ronald Walpole", 9, 2012, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Aplicada", "Richard Levin", 7, 1999, "Matematica", "Estadistica"};
    libros[contador++] = {"Estadistica Inferencial", "Mario Triola", 13, 2018, "Matematica", "Estadistica"};
    libros[contador++] = {"Introduccion a la Estadistica", "Sheldon Ross", 3, 2010, "Matematica", "Estadistica"};

    // Matematica - Trigonometria
    libros[contador++] = {"Trigonometria", "Luis Arana", 1, 2015, "Matematica", "Trigonometria"};
    libros[contador++] = {"Curso de Trigonometria", "Pedro Poma", 2, 2017, "Matematica", "Trigonometria"};
    libros[contador++] = {"Trigonometria Plana", "Maria Castro", 1, 2016, "Matematica", "Trigonometria"};
    libros[contador++] = {"Identidades Trigonometricas", "Jose Rojas", 2, 2019, "Matematica", "Trigonometria"};
    libros[contador++] = {"Funciones Trigonometricas", "Walter Apaza", 1, 2021, "Matematica", "Trigonometria"};
    
    // Ciencias - Fisica
    libros[contador++] = {"Fisica Universitaria", "Hugh D. Young", 13, 2012, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica Conceptual", "Paul G. Hewitt", 12, 2010, "Ciencias", "Fisica"};
    libros[contador++] = {"Fundamentos de Fisica", "David Halliday", 10, 2014, "Ciencias", "Fisica"};
    libros[contador++] = {"Fisica para la Ciencia y la Tecnologia", "Paul Tipler", 6, 2008, "Ciencias", "Fisica"};
    libros[contador++] = {"Problemas de Fisica General", "I.E. Irodov", 1, 2001, "Ciencias", "Fisica"};

    // Ciencias - Quimica
    libros[contador++] = {"Quimica", "Raymond Chang", 12, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica General", "Ralph H. Petrucci", 11, 2011, "Ciencias", "Quimica"};
    libros[contador++] = {"Principios de Quimica", "Paula Yurkanis Bruice", 7, 2014, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica Organica", "John McMurry", 9, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"Quimica Inorganica", "Gary L. Miessler", 5, 2014, "Ciencias", "Quimica"};

    // Ciencias - Biologia
    libros[contador++] = {"Biologia", "Neil A. Campbell", 9, 2012, "Ciencias", "Biologia"};
    libros[contador++] = {"Fundamentos de Biologia", "Solomon Berg", 7, 2010, "Ciencias", "Biologia"};
    libros[contador++] = {"Biologia Celular y Molecular", "Gerald Karp", 8, 2016, "Ciencias", "Biologia"};
    libros[contador++] = {"Anatomia y Fisiologia", "Elaine N. Marieb", 10, 2015, "Ciencias", "Biologia"};
    libros[contador++] = {"Microbiologia", "Tortora", 11, 2014, "Ciencias", "Biologia"};

    // Ciencias - Astronomia
    libros[contador++] = {"Astronomia: Una Guia", "Ian Ridpath", 3, 2015, "Ciencias", "Astronomia"};
    libros[contador++] = {"Cosmos", "Carl Sagan", 1, 1980, "Ciencias", "Astronomia"};
    libros[contador++] = {"Astrofisica para Gente con Prisa", "Neil deGrasse Tyson", 1, 2017, "Ciencias", "Astronomia"};
    libros[contador++] = {"Introduccion a la Astronomia", "Pedro Poma", 2, 2016, "Ciencias", "Astronomia"};
    libros[contador++] = {"El Universo en una Cascara de Nuez", "Stephen Hawking", 1, 2001, "Ciencias", "Astronomia"};

    // Ciencias - Ecologia
    libros[contador++] = {"Ecologia", "Cain, Bowman y Hacker", 3, 2014, "Ciencias", "Ecologia"};
    libros[contador++] = {"Principios de Ecologia", "Walter Apaza", 1, 2019, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Aplicada", "S. R. Carpenter", 1, 2012, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Humana", "Paul Shepard", 2, 2001, "Ciencias", "Ecologia"};
    libros[contador++] = {"Ecologia Urbana", "Luis Arana", 1, 2018, "Ciencias", "Ecologia"};

    // Literatura - Peruana
    libros[contador++] = {"Los Heraldos Negros", "Cesar Vallejo", 1, 1919, "Literatura", "Peruana"};
    libros[contador++] = {"La Casa de Carton", "Martin Adan", 1, 1928, "Literatura", "Peruana"};
    libros[contador++] = {"Redoble por Rancas", "Manuel Scorza", 1, 1970, "Literatura", "Peruana"};
    libros[contador++] = {"El Pez de Oro", "Gamaleon Churata", 1, 1957, "Literatura", "Peruana"};
    libros[contador++] = {"El Sexto", "Jose Maria Arguedas", 1, 1961, "Literatura", "Peruana"};

    // Literatura - Latinoamericana
    libros[contador++] = {"Rayuela", "Julio Cortazar", 1, 1963, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Pedro Paramo", "Juan Rulfo", 1, 1955, "Literatura", "Latinoamericana"};
    libros[contador++] = {"El Tunel", "Ernesto Sabato", 1, 1948, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Aura", "Carlos Fuentes", 1, 1962, "Literatura", "Latinoamericana"};
    libros[contador++] = {"Sobre Heroes y Tumbas", "Ernesto Sabato", 1, 1961, "Literatura", "Latinoamericana"};

    // Literatura - Universal
    libros[contador++] = {"1984", "George Orwell", 1, 1949, "Literatura", "Universal"};
    libros[contador++] = {"Matar a un Ruisenor", "Harper Lee", 1, 1960, "Literatura", "Universal"};
    libros[contador++] = {"Crimen y Castigo", "Fiodor Dostoievski", 1, 1866, "Literatura", "Universal"};
    libros[contador++] = {"Orgullo y Prejuicio", "Jane Austen", 1, 1813, "Literatura", "Universal"};
    libros[contador++] = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1, 1605, "Literatura", "Universal"};

    // Literatura - Clasica
    libros[contador++] = {"La Iliada", "Homero", 1, -750, "Literatura", "Clasica"};
    libros[contador++] = {"La Odisea", "Homero", 1, -700, "Literatura", "Clasica"};
    libros[contador++] = {"La Eneida", "Virgilio", 1, -19, "Literatura", "Clasica"};
    libros[contador++] = {"Edipo Rey", "Sofocles", 1, -429, "Literatura", "Clasica"};
    libros[contador++] = {"Las Metamorfosis", "Ovidio", 1, 8, "Literatura", "Clasica"};

    // Literatura - Contemporanea
    libros[contador++] = {"Kafka en la Orilla", "Haruki Murakami", 1, 2002, "Literatura", "Contemporanea"};
    libros[contador++] = {"Nunca Me Abandones", "Kazuo Ishiguro", 1, 2005, "Literatura", "Contemporanea"};
    libros[contador++] = {"Los Detectives Salvajes", "Roberto Bolaño", 1, 1998, "Literatura", "Contemporanea"};
    libros[contador++] = {"El Nino con el Pijama de Rayas", "John Boyne", 1, 2006, "Literatura", "Contemporanea"};
    libros[contador++] = {"El Nombre del Viento", "Patrick Rothfuss", 1, 2007, "Literatura", "Contemporanea"};

    //Historia - Peruana
    libros[contador++] = {"Breve Historia del Peru", "Franklin Pease G.Y.", 1, 1995, "Historia", "Peruana"};
    libros[contador++] = {"Los Incas: Reyes del Sol", "Victor W. von Hagen", 1, 1961, "Historia", "Peruana"};
    libros[contador++] = {"La Guerra del Pacifico", "Jorge Basadre Grohmann", 1, 1946, "Historia", "Peruana"};
    libros[contador++] = {"Historia de la Republica del Peru", "Jorge Basadre Grohmann", 11, 2005, "Historia", "Peruana"};
    libros[contador++] = {"El Conflicto Armado Interno en Peru", "CVR", 1, 2003, "Historia", "Peruana"};

    //Historia - Universal
    libros[contador++] = {"Sapiens: De Animales a Dioses", "Yuval Noah Harari", 1, 2014, "Historia", "Universal"};
    libros[contador++] = {"Una Breve Historia del Mundo", "Ernst Gombrich", 1, 1935, "Historia", "Universal"};
    libros[contador++] = {"Armas, Germenes y Acero", "Jared Diamond", 1, 1997, "Historia", "Universal"};
    libros[contador++] = {"Historia Universal", "H.G. Wells", 1, 1920, "Historia", "Universal"};
    libros[contador++] = {"La Historia del Mundo en Cien Objetos", "Neil MacGregor", 1, 2010, "Historia", "Universal"};

    //Historia - Antigua
    libros[contador++] = {"Historia de Roma", "Mary Beard", 1, 2015, "Historia", "Antigua"};
    libros[contador++] = {"El Antiguo Egipto", "Toby Wilkinson", 1, 2010, "Historia", "Antigua"};
    libros[contador++] = {"Los Griegos", "H.D.F. Kitto", 1, 1951, "Historia", "Antigua"};
    libros[contador++] = {"El Cercano Oriente Antiguo", "Marc Van De Mieroop", 2, 2016, "Historia", "Antigua"};
    libros[contador++] = {"La Guerra del Peloponeso", "Tucidides", 1, -431, "Historia", "Antigua"};

    //Historia - Moderna
    libros[contador++] = {"El Siglo de las Luces", "Alejo Carpentier", 1, 1962, "Historia", "Moderna"};
    libros[contador++] = {"La Revolucion Francesa", "Michel Vovelle", 1, 1993, "Historia", "Moderna"};
    libros[contador++] = {"Historia de la Revolucion Rusa", "Leon Trotsky", 1, 1930, "Historia", "Moderna"};
    libros[contador++] = {"La Era de las Revoluciones", "Eric Hobsbawm", 1, 1962, "Historia", "Moderna"};
    libros[contador++] = {"El Mundo de Ayer", "Stefan Zweig", 1, 1942, "Historia", "Moderna"};

    //Historia - Contemporanea
    libros[contador++] = {"El Fin de la Historia y el Ultimo Hombre", "Francis Fukuyama", 1, 1992, "Historia", "Contemporanea"};
    libros[contador++] = {"La Era de los Extremos", "Eric Hobsbawm", 1, 1994, "Historia", "Contemporanea"};
    libros[contador++] = {"Los Origenes de la Segunda Guerra Mundial", "A.J.P. Taylor", 1, 1961, "Historia", "Contemporanea"};
    libros[contador++] = {"Guerra y Paz", "Leon Tolstoi", 1, 1869, "Historia", "Contemporanea"};
    libros[contador++] = {"Un Mundo Feliz", "Aldous Huxley", 1, 1932, "Historia", "Contemporanea"};

    //Filosofia - Etica
    libros[contador++] = {"Etica a Nicomaco", "Aristoteles", 1, -340, "Filosofia", "Etica"};
    libros[contador++] = {"Fundamentacion de la Metafisica de las Costumbres", "Immanuel Kant", 1, 1785, "Filosofia", "Etica"};
    libros[contador++] = {"Utilitarismo", "John Stuart Mill", 1, 1861, "Filosofia", "Etica"};
    libros[contador++] = {"Asi Hablo Zaratustra", "Friedrich Nietzsche", 1, 1883, "Filosofia", "Etica"};
    libros[contador++] = {"Sobre la Libertad", "John Stuart Mill", 1, 1859, "Filosofia", "Etica"};

    //Filosofia - Logica
    libros[contador++] = {"Logica", "Irving M. Copi", 14, 2011, "Filosofia", "Logica"};
    libros[contador++] = {"Introduccion a la Logica", "Alfred Tarski", 1, 1941, "Filosofia", "Logica"};
    libros[contador++] = {"Principia Mathematica", "Bertrand Russell", 1, 1910, "Filosofia", "Logica"};
    libros[contador++] = {"Investigaciones Filosoficas", "Ludwig Wittgenstein", 1, 1953, "Filosofia", "Logica"};
    libros[contador++] = {"El Organon", "Aristoteles", 1, -350, "Filosofia", "Logica"};

    //Filosofia - Metafisica
    libros[contador++] = {"Metafisica", "Aristoteles", 1, -350, "Filosofia", "Metafisica"};
    libros[contador++] = {"Critica de la Razon Pura", "Immanuel Kant", 1, 1781, "Filosofia", "Metafisica"};
    libros[contador++] = {"Ser y Tiempo", "Martin Heidegger", 1, 1927, "Filosofia", "Metafisica"};
    libros[contador++] = {"El Mundo como Voluntad y Representacion", "Arthur Schopenhauer", 1, 1818, "Filosofia", "Metafisica"};
    libros[contador++] = {"Discurso del Metodo", "Rene Descartes", 1, 1637, "Filosofia", "Metafisica"};

    //Filosofia - Epistemologia
    libros[contador++] = {"Investigacion sobre el Entendimiento Humano", "David Hume", 1, 1748, "Filosofia", "Epistemologia"};
    libros[contador++] = {"El Conocimiento Humano", "Bertrand Russell", 1, 1948, "Filosofia", "Epistemologia"};
    libros[contador++] = {"Logica de la Investigacion Cientifica", "Karl Popper", 1, 1934, "Filosofia", "Epistemologia"};
    libros[contador++] = {"Estructura de las Revoluciones Cientificas", "Thomas S. Kuhn", 1, 1962, "Filosofia", "Epistemologia"};
    libros[contador++] = {"Teoria del Conocimiento", "Johannes Hessen", 1, 1926, "Filosofia", "Epistemologia"};

    //Computacion - Programacion
    libros[contador++] = {"Principios de Programacion con C++", "Bjarne Stroustrup", 2, 2014, "Computacion", "Programacion"};
    libros[contador++] = {"Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", 1, 2008, "Computacion", "Programacion"};
    libros[contador++] = {"Code Complete", "Steve McConnell", 2, 2004, "Computacion", "Programacion"};
    libros[contador++] = {"Python Crash Course", "Eric Matthes", 2, 2019, "Computacion", "Programacion"};
    libros[contador++] = {"Refactoring: Improving the Design of Existing Code", "Martin Fowler", 2, 2018, "Computacion", "Programacion"};

    //Computacion - Algoritmos
    libros[contador++] = {"Introduccion a los Algoritmos", "Thomas H. Cormen", 4, 2022, "Computacion", "Algoritmos"};
    libros[contador++] = {"Algoritmos", "Robert Sedgewick", 4, 2011, "Computacion", "Algoritmos"};
    libros[contador++] = {"Algoritmos y estructuras de datos", "Víctor R. Torres Soto", 2, 2018, "Computacion", "Algoritmos"};
    libros[contador++] = {"Fundamentos de algoritmos", "César A. Gonzales Rengifo", 1, 2021, "Computacion", "Algoritmos"};
    libros[contador++] = {"Algoritmos y Estructuras de Datos", "Niklaus Wirth", 1, 1986, "Computacion", "Algoritmos"};

    //Computacion - Redes
    libros[contador++] = {"Redes de Computadoras", "Andrew S. Tanenbaum", 5, 2011, "Computacion", "Redes"};
    libros[contador++] = {"TCP/IP Illustrated, Vol. 1: The Protocols", "W. Richard Stevens", 1, 1993, "Computacion", "Redes"};
    libros[contador++] = {"CompTIA Network+ Study Guide", "Todd Lammle", 5, 2021, "Computacion", "Redes"};
    libros[contador++] = {"Interconexiones de Redes con TCP/IP Volumen 1", "Douglas E. Comer", 6, 2013, "Computacion", "Redes"};
    libros[contador++] = {"Cisco CCNA Routing and Switching Official Cert Guide", "Wendell Odom", 2, 2013, "Computacion", "Redes"};

    //Computacion - IA
    libros[contador++] = {"Inteligencia Artificial: Un Enfoque Moderno", "Stuart Russell", 4, 2020, "Computacion", "IA"};
    libros[contador++] = {"Aprendizaje Automatico", "Tom M. Mitchell", 1, 1997, "Computacion", "IA"};
    libros[contador++] = {"Deep Learning", "Ian Goodfellow", 1, 2016, "Computacion", "IA"};
    libros[contador++] = {"Programacion de la Inteligencia Artificial en Python", "Peter Norvig", 3, 2009, "Computacion", "IA"};
    libros[contador++] = {"Redes Neuronales y Aprendizaje Profundo", "Michael Nielsen", 1, 2015, "Computacion", "IA"};

    //Computacion - Bases de Datos
    libros[contador++] = {"Fundamentos de Sistemas de Bases de Datos", "Elmasri & Navathe", 7, 2015, "Computacion", "Bases de Datos"};
    libros[contador++] = {"SQL para Dummies", "Allen G. Taylor", 9, 2017, "Computacion", "Bases de Datos"};
    libros[contador++] = {"Database System Concepts", "Abraham Silberschatz", 7, 2019, "Computacion", "Bases de Datos"};
    libros[contador++] = {"Disenio de Bases de Datos Relacionales", "C.J. Date", 4, 2000, "Computacion", "Bases de Datos"};

    // Economia - Microeconomia
    libros[contador++] = {"Principios de microeconomia", "Rosa Salazar", 1, 2018, "Economia", "Microeconomia"};
    libros[contador++] = {"Microeconomia intermedia", "Luis Camargo", 2, 2019, "Economia", "Microeconomia"};
    libros[contador++] = {"Teoria del consumidor", "Claudia Poma", 1, 2020, "Economia", "Microeconomia"};
    libros[contador++] = {"Analisis de oferta y demanda", "Carlos Huamani", 2, 2021, "Economia", "Microeconomia"};
    libros[contador++] = {"Estructura de mercados", "Elena Quispe", 1, 2022, "Economia", "Microeconomia"};

    // Economia - Macroeconomia
    libros[contador++] = {"Fundamentos de macroeconomia", "Sofia Ramos", 1, 2018, "Economia", "Macroeconomia"};
    libros[contador++] = {"Macroeconomia intermedia", "Ricardo Calla", 2, 2019, "Economia", "Macroeconomia"};
    libros[contador++] = {"Inflacion y desempleo", "Carmen Huanca", 1, 2020, "Economia", "Macroeconomia"};
    libros[contador++] = {"Cuentas nacionales", "Javier Ticona", 2, 2021, "Economia", "Macroeconomia"};
    libros[contador++] = {"Politica monetaria", "Tatiana Chahuares", 1, 2022, "Economia", "Macroeconomia"};

    // Economia - Finanzas
    libros[contador++] = {"Introduccion a las finanzas", "Hugo Poma", 1, 2018, "Economia", "Finanzas"};
    libros[contador++] = {"Finanzas corporativas", "Lorena Huamani", 2, 2019, "Economia", "Finanzas"};
    libros[contador++] = {"Mercado de capitales", "Jaime Chura", 1, 2020, "Economia", "Finanzas"};
    libros[contador++] = {"Inversiones financieras", "Lucero Lazo", 2, 2021, "Economia", "Finanzas"};
    libros[contador++] = {"Riesgo y rendimiento", "Victor Caceres", 1, 2022, "Economia", "Finanzas"};

    // Economia - Contabilidad
    libros[contador++] = {"Contabilidad general", "Roxana Nina", 1, 2018, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad financiera", "Luis Huayta", 2, 2019, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad de costos", "Paola Rojas", 1, 2020, "Economia", "Contabilidad"};
    libros[contador++] = {"Contabilidad gerencial", "Juliana Chambi", 2, 2021, "Economia", "Contabilidad"};
    libros[contador++] = {"Estados financieros", "Erick Mamani", 1, 2022, "Economia", "Contabilidad"};

    // Ingenieria - Civil
    libros[contador++] = {"Fundamentos de ingenieria civil", "Luis Cardenas", 1, 2018, "Ingenieria", "Civil"};
    libros[contador++] = {"Diseño estructural basico", "Ana Rojas", 2, 2019, "Ingenieria", "Civil"};
    libros[contador++] = {"Construccion de carreteras", "Julio Pacheco", 1, 2020, "Ingenieria", "Civil"};
    libros[contador++] = {"Mecanica de suelos", "Rosa Luyo", 3, 2021, "Ingenieria", "Civil"};
    libros[contador++] = {"Hormigon armado", "Carlos Ninanya", 1, 2022, "Ingenieria", "Civil"};

    // Ingenieria - Mecanica
    libros[contador++] = {"Termodinamica basica", "Oscar Mamani", 1, 2019, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Resistencia de materiales", "Lucia Vargas", 2, 2020, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Mecanica de fluidos", "Pedro Nina", 3, 2021, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Maquinas termicas", "Diana Quispe", 1, 2022, "Ingenieria", "Mecanica"};
    libros[contador++] = {"Diseño de maquinas", "Hector Ancco", 2, 2023, "Ingenieria", "Mecanica"};

    // Ingenieria - Electrica
    libros[contador++] = {"Circuitos electricos", "Cesar Ramos", 1, 2018, "Ingenieria", "Electrica"};
    libros[contador++] = {"Maquinas electricas", "Natalia Huamani", 2, 2020, "Ingenieria", "Electrica"};
    libros[contador++] = {"Electrotecnia basica", "Luis Chahuares", 1, 2019, "Ingenieria", "Electrica"};
    libros[contador++] = {"Instalaciones electricas", "Veronica Salas", 3, 2021, "Ingenieria", "Electrica"};
    libros[contador++] = {"Transformadores", "Hugo Quispe", 2, 2022, "Ingenieria", "Electrica"};

    // Ingenieria - Sistemas
    libros[contador++] = {"Programacion en C++", "Fernando Quispe", 1, 2018, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Base de datos relacional", "Roxana Calla", 2, 2019, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Ingenieria de software", "Carlos Vizcarra", 3, 2020, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Sistemas operativos", "Isabel Nina", 1, 2021, "Ingenieria", "Sistemas"};
    libros[contador++] = {"Redes de computadoras", "Jaime Chura", 2, 2022, "Ingenieria", "Sistemas"};

    // Ingenieria - Industrial
    libros[contador++] = {"Gestion de calidad", "Erika Vilca", 1, 2018, "Ingenieria", "Industrial"};
    libros[contador++] = {"Logistica y produccion", "Jorge Caceres", 2, 2019, "Ingenieria", "Industrial"};
    libros[contador++] = {"Investigacion de operaciones", "Carla Ludeña", 3, 2020, "Ingenieria", "Industrial"};
    libros[contador++] = {"Seguridad industrial", "Walter Huamani", 1, 2021, "Ingenieria", "Industrial"};
    libros[contador++] = {"Gestion de procesos", "Ines Paredes", 2, 2022, "Ingenieria", "Industrial"};

    // Medicina - Anatomia
    libros[contador++] = {"Anatomia humana basica", "Luis Huamani", 1, 2018, "Medicina", "Anatomia"};
    libros[contador++] = {"Atlas de anatomia", "Rosa Quispe", 2, 2020, "Medicina", "Anatomia"};
    libros[contador++] = {"Anatomia para estudiantes", "Jorge Apaza", 3, 2019, "Medicina", "Anatomia"};
    libros[contador++] = {"Sistema oseo", "Elena Paredes", 1, 2021, "Medicina", "Anatomia"};
    libros[contador++] = {"Anatomia del sistema nervioso", "Carmen Luyo", 2, 2022, "Medicina", "Anatomia"};

    // Medicina - Fisiologia
    libros[contador++] = {"Fisiologia humana", "Lucia Valverde", 1, 2018, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fundamentos de fisiologia", "Oscar Mamani", 2, 2020, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia del sistema digestivo", "Sandra Huayta", 1, 2021, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia cardiovascular", "Victor Ancco", 2, 2022, "Medicina", "Fisiologia"};
    libros[contador++] = {"Fisiologia pulmonar", "Mercedes Chuquimia", 1, 2019, "Medicina", "Fisiologia"};

    // Medicina - Farmacologia
    libros[contador++] = {"Introduccion a la farmacologia", "Daniela Vizcarra", 1, 2020, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacos esenciales", "Andres Ramos", 2, 2021, "Medicina", "Farmacologia"};
    libros[contador++] = {"Manual de farmacologia", "Veronica Zevallos", 1, 2022, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacologia clinica", "Ernesto Guzman", 1, 2019, "Medicina", "Farmacologia"};
    libros[contador++] = {"Farmacocinetica basica", "Milagros Poma", 2, 2020, "Medicina", "Farmacologia"};

    // Medicina - General
    libros[contador++] = {"Principios de medicina general", "Isabel Flores", 1, 2018, "Medicina", "General"};
    libros[contador++] = {"Diagnostico clinico", "Felix Paredes", 2, 2019, "Medicina", "General"};
    libros[contador++] = {"Tratamiento ambulatorio", "Ruben Chambi", 1, 2020, "Medicina", "General"};
    libros[contador++] = {"Medicina preventiva", "Cecilia Asto", 2, 2021, "Medicina", "General"};
    libros[contador++] = {"Salud publica", "Norma Chahuares", 1, 2022, "Medicina", "General"};

    // Idioma - Ingles
    libros[contador++] = {"Guia de Ingles", "Maria Lopez", 1, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"Manual de Ingles", "Maria Lopez", 2, 2021, "Idioma", "Ingles"};
    libros[contador++] = {"Aprende Ingles", "Maria Lopez", 1, 2022, "Idioma", "Ingles"};
    libros[contador++] = {"Curso basico de Ingles", "Maria Lopez", 3, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"Introduccion a Ingles", "Maria Lopez", 1, 2021, "Idioma", "Ingles"};

    // Idioma - Frances
    libros[contador++] = {"Guia de Frances", "Jean Dupont", 1, 2020, "Idioma", "Frances"};
    libros[contador++] = {"Manual de Frances", "Jean Dupont", 2, 2021, "Idioma", "Frances"};
    libros[contador++] = {"Aprende Frances", "Jean Dupont", 1, 2022, "Idioma", "Frances"};
    libros[contador++] = {"Curso basico de Frances", "Jean Dupont", 3, 2020, "Idioma", "Frances"};
    libros[contador++] = {"Introduccion a Frances", "Jean Dupont", 1, 2021, "Idioma", "Frances"};

    // Idioma - Quechua
    libros[contador++] = {"Guia de Quechua", "Rumi Huaman", 1, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"Manual de Quechua", "Rumi Huaman", 2, 2021, "Idioma", "Quechua"};
    libros[contador++] = {"Aprende Quechua", "Rumi Huaman", 1, 2022, "Idioma", "Quechua"};
    libros[contador++] = {"Curso basico de Quechua", "Rumi Huaman", 3, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"Introduccion a Quechua", "Rumi Huaman", 1, 2021, "Idioma", "Quechua"};

    // Idioma - Aleman
    libros[contador++] = {"Guia de Aleman", "Hans Becker", 1, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"Manual de Aleman", "Hans Becker", 2, 2021, "Idioma", "Aleman"};
    libros[contador++] = {"Aprende Aleman", "Hans Becker", 1, 2022, "Idioma", "Aleman"};
    libros[contador++] = {"Curso basico de Aleman", "Hans Becker", 3, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"Introduccion a Aleman", "Hans Becker", 1, 2021, "Idioma", "Aleman"};

    // Idioma - Chino
    libros[contador++] = {"Guia de Chino", "Li Zhang", 1, 2020, "Idioma", "Chino"};
    libros[contador++] = {"Manual de Chino", "Li Zhang", 2, 2021, "Idioma", "Chino"};
    libros[contador++] = {"Aprende Chino", "Li Zhang", 1, 2022, "Idioma", "Chino"};
    libros[contador++] = {"Curso basico de Chino", "Li Zhang", 3, 2020, "Idioma", "Chino"};
    libros[contador++] = {"Introduccion a Chino", "Li Zhang", 1, 2021, "Idioma", "Chino"};

}
