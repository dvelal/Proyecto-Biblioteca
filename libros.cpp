#include"libros.h"

// Permite usar la lista de inicialización {} para llenar los campos de una estructura en el mismo orden en que fueron definidos.
void cargarLibrosPredefinidos(Libro libros[], int &contador) {

    // Matematica - Calculo
    libros[contador++] = {"0001", "Calculo", "James Stewart", 8, 2020, "Matematica", "Calculo"};
    libros[contador++] = {"0002", "Calculo I", "Luis Arana", 2, 2019, "Matematica", "Calculo"};
    libros[contador++] = {"0003", "Calculo Diferencial", "Julio Rios", 3, 2016, "Matematica", "Calculo"};
    libros[contador++] = {"0004", "Calculo Integral", "Pedro Poma", 4, 2018, "Matematica", "Calculo"};
    libros[contador++] = {"0005", "Curso de Calculo", "Carlos Zavala", 1, 2015, "Matematica", "Calculo"};

    // Matematica - Algebra
    libros[contador++] = {"0006", "Algebra Lineal", "David Lay", 5, 2016, "Matematica", "Algebra"};
    libros[contador++] = {"0007", "Algebra I", "Luis Arana", 3, 2020, "Matematica", "Algebra"};
    libros[contador++] = {"0008", "Problemas de Algebra", "Walter Apaza", 2, 2019, "Matematica", "Algebra"};
    libros[contador++] = {"0009", "Algebra Elemental", "Cesar Delgado", 1, 2015, "Matematica", "Algebra"};
    libros[contador++] = {"0010", "Curso de Algebra", "Pedro Poma", 4, 2017, "Matematica", "Algebra"};

    // Matematica - Geometria
    libros[contador++] = {"0011", "Geometria Euclidiana", "Fernando Cardenas", 1, 2015, "Matematica", "Geometria"};
    libros[contador++] = {"0012", "Geometria Analitica", "Maria Romero", 2, 2017, "Matematica", "Geometria"};
    libros[contador++] = {"0013", "Geometria Plana", "Luis Suarez", 3, 2016, "Matematica", "Geometria"};
    libros[contador++] = {"0014", "Geometria en el Espacio", "Pedro Diaz", 2, 2014, "Matematica", "Geometria"};
    libros[contador++] = {"0015", "Figuras Geometricas", "Juan Vega", 1, 2013, "Matematica", "Geometria"};

    // Matematica - Aritmetica
    libros[contador++] = {"0016", "Aritmetica I", "Luis Arana", 2, 2015, "Matematica", "Aritmetica"};
    libros[contador++] = {"0017", "Aritmetica Basica", "Carmen Flores", 1, 2016, "Matematica", "Aritmetica"};
    libros[contador++] = {"0018", "Curso de Aritmetica", "Pedro Poma", 2, 2017, "Matematica", "Aritmetica"};
    libros[contador++] = {"0019", "Aritmetica para Pre", "Walter Apaza", 1, 2014, "Matematica", "Aritmetica"};
    libros[contador++] = {"0020", "Teoria de Numeros", "Carlos Rojas", 2, 2020, "Matematica", "Aritmetica"};

    // Matematica - Estadistica
    libros[contador++] = {"0021", "Estadistica Matematica", "John Freund", 8, 2010, "Matematica", "Estadistica"};
    libros[contador++] = {"0022", "Probabilidad y Estadistica", "Ronald Walpole", 9, 2012, "Matematica", "Estadistica"};
    libros[contador++] = {"0023", "Estadistica Aplicada", "Richard Levin", 7, 1999, "Matematica", "Estadistica"};
    libros[contador++] = {"0024", "Estadistica Inferencial", "Mario Triola", 13, 2018, "Matematica", "Estadistica"};
    libros[contador++] = {"0025", "Introduccion a la Estadistica", "Sheldon Ross", 3, 2010, "Matematica", "Estadistica"};

    // Matematica - Trigonometria
    libros[contador++] = {"0026", "Trigonometria", "Luis Arana", 1, 2015, "Matematica", "Trigonometria"};
    libros[contador++] = {"0027", "Curso de Trigonometria", "Pedro Poma", 2, 2017, "Matematica", "Trigonometria"};
    libros[contador++] = {"0028", "Trigonometria Plana", "Maria Castro", 1, 2016, "Matematica", "Trigonometria"};
    libros[contador++] = {"0029", "Identidades Trigonometricas", "Jose Rojas", 2, 2019, "Matematica", "Trigonometria"};
    libros[contador++] = {"0030", "Funciones Trigonometricas", "Walter Apaza", 1, 2021, "Matematica", "Trigonometria"};
    
    // Ciencias - Fisica
    libros[contador++] = {"0031", "Fisica Universitaria", "Hugh D. Young", 13, 2012, "Ciencias", "Fisica"};
    libros[contador++] = {"0032", "Fisica Conceptual", "Paul G. Hewitt", 12, 2010, "Ciencias", "Fisica"};
    libros[contador++] = {"0033", "Fundamentos de Fisica", "David Halliday", 10, 2014, "Ciencias", "Fisica"};
    libros[contador++] = {"0034", "Fisica para la Ciencia y la Tecnologia", "Paul Tipler", 6, 2008, "Ciencias", "Fisica"};
    libros[contador++] = {"0035", "Problemas de Fisica General", "I.E. Irodov", 1, 2001, "Ciencias", "Fisica"};

    // Ciencias - Quimica
    libros[contador++] = {"0036", "Quimica", "Raymond Chang", 12, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"0037", "Quimica General", "Ralph H. Petrucci", 11, 2011, "Ciencias", "Quimica"};
    libros[contador++] = {"0038", "Principios de Quimica", "Paula Yurkanis Bruice", 7, 2014, "Ciencias", "Quimica"};
    libros[contador++] = {"0039", "Quimica Organica", "John McMurry", 9, 2016, "Ciencias", "Quimica"};
    libros[contador++] = {"0040", "Quimica Inorganica", "Gary L. Miessler", 5, 2014, "Ciencias", "Quimica"};

    // Ciencias - Biologia
    libros[contador++] = {"0041", "Biologia", "Neil A. Campbell", 9, 2012, "Ciencias", "Biologia"};
    libros[contador++] = {"0042", "Fundamentos de Biologia", "Solomon Berg", 7, 2010, "Ciencias", "Biologia"};
    libros[contador++] = {"0043", "Biologia Celular y Molecular", "Gerald Karp", 8, 2016, "Ciencias", "Biologia"};
    libros[contador++] = {"0044", "Anatomia y Fisiologia", "Elaine N. Marieb", 10, 2015, "Ciencias", "Biologia"};
    libros[contador++] = {"0045", "Microbiologia", "Tortora", 11, 2014, "Ciencias", "Biologia"};

    // Ciencias - Astronomia
    libros[contador++] = {"0046", "Astronomia: Una Guia", "Ian Ridpath", 3, 2015, "Ciencias", "Astronomia"};
    libros[contador++] = {"0047", "Cosmos", "Carl Sagan", 1, 1980, "Ciencias", "Astronomia"};
    libros[contador++] = {"0048", "Astrofisica para Gente con Prisa", "Neil deGrasse Tyson", 1, 2017, "Ciencias", "Astronomia"};
    libros[contador++] = {"0049", "Introduccion a la Astronomia", "Pedro Poma", 2, 2016, "Ciencias", "Astronomia"};
    libros[contador++] = {"0050", "El Universo en una Cascara de Nuez", "Stephen Hawking", 1, 2001, "Ciencias", "Astronomia"};

    // Ciencias - Ecologia
    libros[contador++] = {"0051", "Ecologia", "Cain, Bowman y Hacker", 3, 2014, "Ciencias", "Ecologia"};
    libros[contador++] = {"0052", "Principios de Ecologia", "Walter Apaza", 1, 2019, "Ciencias", "Ecologia"};
    libros[contador++] = {"0053", "Ecologia Aplicada", "S. R. Carpenter", 1, 2012, "Ciencias", "Ecologia"};
    libros[contador++] = {"0054", "Ecologia Humana", "Paul Shepard", 2, 2001, "Ciencias", "Ecologia"};
    libros[contador++] = {"0055", "Ecologia Urbana", "Luis Arana", 1, 2018, "Ciencias", "Ecologia"};

    // Literatura - Peruana
    libros[contador++] = {"0056", "Los Heraldos Negros", "Cesar Vallejo", 1, 1919, "Literatura", "Peruana"};
    libros[contador++] = {"0057", "La Casa de Carton", "Martin Adan", 1, 1928, "Literatura", "Peruana"};
    libros[contador++] = {"0058", "Redoble por Rancas", "Manuel Scorza", 1, 1970, "Literatura", "Peruana"};
    libros[contador++] = {"0059", "El Pez de Oro", "Gamaleon Churata", 1, 1957, "Literatura", "Peruana"};
    libros[contador++] = {"0060", "El Sexto", "Jose Maria Arguedas", 1, 1961, "Literatura", "Peruana"};

    // Literatura - Latinoamericana
    libros[contador++] = {"0061", "Rayuela", "Julio Cortazar", 1, 1963, "Literatura", "Latinoamericana"};
    libros[contador++] = {"0062", "Pedro Paramo", "Juan Rulfo", 1, 1955, "Literatura", "Latinoamericana"};
    libros[contador++] = {"0063", "El Tunel", "Ernesto Sabato", 1, 1948, "Literatura", "Latinoamericana"};
    libros[contador++] = {"0064", "Aura", "Carlos Fuentes", 1, 1962, "Literatura", "Latinoamericana"};
    libros[contador++] = {"0065", "Sobre Heroes y Tumbas", "Ernesto Sabato", 1, 1961, "Literatura", "Latinoamericana"};

    // Literatura - Universal
    libros[contador++] = {"0066", "1984", "George Orwell", 1, 1949, "Literatura", "Universal"};
    libros[contador++] = {"0067", "Matar a un Ruisenor", "Harper Lee", 1, 1960, "Literatura", "Universal"};
    libros[contador++] = {"0068", "Crimen y Castigo", "Fiodor Dostoievski", 1, 1866, "Literatura", "Universal"};
    libros[contador++] = {"0069", "Orgullo y Prejuicio", "Jane Austen", 1, 1813, "Literatura", "Universal"};
    libros[contador++] = {"0070", "Don Quijote de la Mancha", "Miguel de Cervantes", 1, 1605, "Literatura", "Universal"};

    // Literatura - Clasica
    libros[contador++] = {"0071", "La Iliada", "Homero", 1, -750, "Literatura", "Clasica"};
    libros[contador++] = {"0072", "La Odisea", "Homero", 1, -700, "Literatura", "Clasica"};
    libros[contador++] = {"0073", "La Eneida", "Virgilio", 1, -19, "Literatura", "Clasica"};
    libros[contador++] = {"0074", "Edipo Rey", "Sofocles", 1, -429, "Literatura", "Clasica"};
    libros[contador++] = {"0075", "Las Metamorfosis", "Ovidio", 1, 8, "Literatura", "Clasica"};

    // Literatura - Contemporanea
    libros[contador++] = {"0076", "Kafka en la Orilla", "Haruki Murakami", 1, 2002, "Literatura", "Contemporanea"};
    libros[contador++] = {"0077", "Nunca Me Abandones", "Kazuo Ishiguro", 1, 2005, "Literatura", "Contemporanea"};
    libros[contador++] = {"0078", "Los Detectives Salvajes", "Roberto Bolaño", 1, 1998, "Literatura", "Contemporanea"};
    libros[contador++] = {"0079", "El Nino con el Pijama de Rayas", "John Boyne", 1, 2006, "Literatura", "Contemporanea"};
    libros[contador++] = {"0080", "El Nombre del Viento", "Patrick Rothfuss", 1, 2007, "Literatura", "Contemporanea"};

    //Historia - Peruana
    libros[contador++] = {"0081", "Breve Historia del Peru", "Franklin Pease G.Y.", 1, 1995, "Historia", "Peruana"};
    libros[contador++] = {"0082", "Los Incas: Reyes del Sol", "Victor W. von Hagen", 1, 1961, "Historia", "Peruana"};
    libros[contador++] = {"0083", "La Guerra del Pacifico", "Jorge Basadre Grohmann", 1, 1946, "Historia", "Peruana"};
    libros[contador++] = {"0084", "Historia de la Republica del Peru", "Jorge Basadre Grohmann", 11, 2005, "Historia", "Peruana"};
    libros[contador++] = {"0085", "El Conflicto Armado Interno en Peru", "CVR", 1, 2003, "Historia", "Peruana"};
    //Historia - Universal
    libros[contador++] = {"0086", "Sapiens: De Animales a Dioses", "Yuval Noah Harari", 1, 2014, "Historia", "Universal"};
    libros[contador++] = {"0087", "Una Breve Historia del Mundo", "Ernst Gombrich", 1, 1935, "Historia", "Universal"};
    libros[contador++] = {"0088", "Armas, Germenes y Acero", "Jared Diamond", 1, 1997, "Historia", "Universal"};
    libros[contador++] = {"0089", "Historia Universal", "H.G. Wells", 1, 1920, "Historia", "Universal"};
    libros[contador++] = {"0090", "La Historia del Mundo en Cien Objetos", "Neil MacGregor", 1, 2010, "Historia", "Universal"};

    //Historia - Antigua
    libros[contador++] = {"0091", "Historia de Roma", "Mary Beard", 1, 2015, "Historia", "Antigua"};
    libros[contador++] = {"0092", "El Antiguo Egipto", "Toby Wilkinson", 1, 2010, "Historia", "Antigua"};
    libros[contador++] = {"0093", "Los Griegos", "H.D.F. Kitto", 1, 1951, "Historia", "Antigua"};
    libros[contador++] = {"0094", "El Cercano Oriente Antiguo", "Marc Van De Mieroop", 2, 2016, "Historia", "Antigua"};
    libros[contador++] = {"0095", "La Guerra del Peloponeso", "Tucidides", 1, -431, "Historia", "Antigua"};

    //Historia - Moderna
    libros[contador++] = {"0096", "El Siglo de las Luces", "Alejo Carpentier", 1, 1962, "Historia", "Moderna"};
    libros[contador++] = {"0097", "La Revolucion Francesa", "Michel Vovelle", 1, 1993, "Historia", "Moderna"};
    libros[contador++] = {"0098", "Historia de la Revolucion Rusa", "Leon Trotsky", 1, 1930, "Historia", "Moderna"};
    libros[contador++] = {"0099", "La Era de las Revoluciones", "Eric Hobsbawm", 1, 1962, "Historia", "Moderna"};
    libros[contador++] = {"0100", "El Mundo de Ayer", "Stefan Zweig", 1, 1942, "Historia", "Moderna"};

    //Historia - Contemporanea
    libros[contador++] = {"0101", "El Fin de la Historia y el Ultimo Hombre", "Francis Fukuyama", 1, 1992, "Historia", "Contemporanea"};
    libros[contador++] = {"0102", "La Era de los Extremos", "Eric Hobsbawm", 1, 1994, "Historia", "Contemporanea"};
    libros[contador++] = {"0103", "Los Origenes de la Segunda Guerra Mundial", "A.J.P. Taylor", 1, 1961, "Historia", "Contemporanea"};
    libros[contador++] = {"0104", "Guerra y Paz", "Leon Tolstoi", 1, 1869, "Historia", "Contemporanea"};
    libros[contador++] = {"0105", "Un Mundo Feliz", "Aldous Huxley", 1, 1932, "Historia", "Contemporanea"};

    //Filosofia - Etica
    libros[contador++] = {"0106", "Etica a Nicomaco", "Aristoteles", 1, -340, "Filosofia", "Etica"};
    libros[contador++] = {"0107", "Fundamentacion de la Metafisica de las Costumbres", "Immanuel Kant", 1, 1785, "Filosofia", "Etica"};
    libros[contador++] = {"0108", "Utilitarismo", "John Stuart Mill", 1, 1861, "Filosofia", "Etica"};
    libros[contador++] = {"0109", "Asi Hablo Zaratustra", "Friedrich Nietzsche", 1, 1883, "Filosofia", "Etica"};
    libros[contador++] = {"0110", "Sobre la Libertad", "John Stuart Mill", 1, 1859, "Filosofia", "Etica"};

    //Filosofia - Logica
    libros[contador++] = {"0111", "Logica", "Irving M. Copi", 14, 2011, "Filosofia", "Logica"};
    libros[contador++] = {"0112", "Introduccion a la Logica", "Alfred Tarski", 1, 1941, "Filosofia", "Logica"};
    libros[contador++] = {"0113", "Principia Mathematica", "Bertrand Russell", 1, 1910, "Filosofia", "Logica"};
    libros[contador++] = {"0114", "Investigaciones Filosoficas", "Ludwig Wittgenstein", 1, 1953, "Filosofia", "Logica"};
    libros[contador++] = {"0115", "El Organon", "Aristoteles", 1, -350, "Filosofia", "Logica"};

    //Filosofia - Metafisica
    libros[contador++] = {"0116", "Metafisica", "Aristoteles", 1, -350, "Filosofia", "Metafisica"};
    libros[contador++] = {"0117", "Critica de la Razon Pura", "Immanuel Kant", 1, 1781, "Filosofia", "Metafisica"};
    libros[contador++] = {"0118", "Ser y Tiempo", "Martin Heidegger", 1, 1927, "Filosofia", "Metafisica"};
    libros[contador++] = {"0119", "El Mundo como Voluntad y Representacion", "Arthur Schopenhauer", 1, 1818, "Filosofia", "Metafisica"};
    libros[contador++] = {"0120", "Discurso del Metodo", "Rene Descartes", 1, 1637, "Filosofia", "Metafisica"};

    //Filosofia - Epistemologia
    libros[contador++] = {"0121", "Investigacion sobre el Entendimiento Humano", "David Hume", 1, 1748, "Filosofia", "Epistemologia"};
    libros[contador++] = {"0122", "El Conocimiento Humano", "Bertrand Russell", 1, 1948, "Filosofia", "Epistemologia"};
    libros[contador++] = {"0123", "Logica de la Investigacion Cientifica", "Karl Popper", 1, 1934, "Filosofia", "Epistemologia"};
    libros[contador++] = {"0124", "Estructura de las Revoluciones Cientificas", "Thomas S. Kuhn", 1, 1962, "Filosofia", "Epistemologia"};
    libros[contador++] = {"0125", "Teoria del Conocimiento", "Johannes Hessen", 1, 1926, "Filosofia", "Epistemologia"};

    //Computacion - Programacion
    libros[contador++] = {"0126", "Principios de Programacion con C++", "Bjarne Stroustrup", 2, 2014, "Computacion", "Programacion"};
    libros[contador++] = {"0127", "Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", 1, 2008, "Computacion", "Programacion"};
    libros[contador++] = {"0128", "Code Complete", "Steve McConnell", 2, 2004, "Computacion", "Programacion"};
    libros[contador++] = {"0129", "Python Crash Course", "Eric Matthes", 2, 2019, "Computacion", "Programacion"};
    libros[contador++] = {"0130", "Refactoring: Improving the Design of Existing Code", "Martin Fowler", 2, 2018, "Computacion", "Programacion"};

    //Computacion - Algoritmos
    libros[contador++] = {"0131", "Introduccion a los Algoritmos", "Thomas H. Cormen", 4, 2022, "Computacion", "Algoritmos"};
    libros[contador++] = {"0132", "Algoritmos", "Robert Sedgewick", 4, 2011, "Computacion", "Algoritmos"};
    libros[contador++] = {"0133", "Algoritmos y estructuras de datos", "Víctor R. Torres Soto", 2, 2018, "Computacion", "Algoritmos"};
    libros[contador++] = {"0134", "Fundamentos de algoritmos", "César A. Gonzales Rengifo", 1, 2021, "Computacion", "Algoritmos"};
    libros[contador++] = {"0135", "Algoritmos y Estructuras de Datos", "Niklaus Wirth", 1, 1986, "Computacion", "Algoritmos"};

    //Computacion - Redes
    libros[contador++] = {"0136", "Redes de Computadoras", "Andrew S. Tanenbaum", 5, 2011, "Computacion", "Redes"};
    libros[contador++] = {"0137", "TCP/IP Illustrated, Vol. 1: The Protocols", "W. Richard Stevens", 1, 1993, "Computacion", "Redes"};
    libros[contador++] = {"0138", "CompTIA Network+ Study Guide", "Todd Lammle", 5, 2021, "Computacion", "Redes"};
    libros[contador++] = {"0139", "Interconexiones de Redes con TCP/IP Volumen 1", "Douglas E. Comer", 6, 2013, "Computacion", "Redes"};
    libros[contador++] = {"0140", "Cisco CCNA Routing and Switching Official Cert Guide", "Wendell Odom", 2, 2013, "Computacion", "Redes"};

    //Computacion - IA
    libros[contador++] = {"0141", "Inteligencia Artificial: Un Enfoque Moderno", "Stuart Russell", 4, 2020, "Computacion", "IA"};
    libros[contador++] = {"0142", "Aprendizaje Automatico", "Tom M. Mitchell", 1, 1997, "Computacion", "IA"};
    libros[contador++] = {"0143", "Deep Learning", "Ian Goodfellow", 1, 2016, "Computacion", "IA"};
    libros[contador++] = {"0144", "Programacion de la Inteligencia Artificial en Python", "Peter Norvig", 3, 2009, "Computacion", "IA"};
    libros[contador++] = {"0145", "Redes Neuronales y Aprendizaje Profundo", "Michael Nielsen", 1, 2015, "Computacion", "IA"};

    //Computacion - Bases de Datos
    libros[contador++] = {"0146", "Fundamentos de Sistemas de Bases de Datos", "Elmasri & Navathe", 7, 2015, "Computacion", "Bases de Datos"};
    libros[contador++] = {"0147", "SQL para Dummies", "Allen G. Taylor", 9, 2017, "Computacion", "Bases de Datos"};
    libros[contador++] = {"0148", "Database System Concepts", "Abraham Silberschatz", 7, 2019, "Computacion", "Bases de Datos"};
    libros[contador++] = {"0149", "Disenio de Bases de Datos Relacionales", "C.J. Date", 4, 2000, "Computacion", "Bases de Datos"};

    // Economia - Microeconomia
    libros[contador++] = {"0150", "Principios de microeconomia", "Rosa Salazar", 1, 2018, "Economia", "Microeconomia"};
    libros[contador++] = {"0151", "Microeconomia intermedia", "Luis Camargo", 2, 2019, "Economia", "Microeconomia"};
    libros[contador++] = {"0152", "Teoria del consumidor", "Claudia Poma", 1, 2020, "Economia", "Microeconomia"};
    libros[contador++] = {"0153", "Analisis de oferta y demanda", "Carlos Huamani", 2, 2021, "Economia", "Microeconomia"};
    libros[contador++] = {"0154", "Estructura de mercados", "Elena Quispe", 1, 2022, "Economia", "Microeconomia"};

    // Economia - Macroeconomia
    libros[contador++] = {"0155", "Fundamentos de macroeconomia", "Sofia Ramos", 1, 2018, "Economia", "Macroeconomia"};
    libros[contador++] = {"0156", "Macroeconomia intermedia", "Ricardo Calla", 2, 2019, "Economia", "Macroeconomia"};
    libros[contador++] = {"0157", "Inflacion y desempleo", "Carmen Huanca", 1, 2020, "Economia", "Macroeconomia"};
    libros[contador++] = {"0158", "Cuentas nacionales", "Javier Ticona", 2, 2021, "Economia", "Macroeconomia"};
    libros[contador++] = {"0159", "Politica monetaria", "Tatiana Chahuares", 1, 2022, "Economia", "Macroeconomia"};

    // Economia - Finanzas
    libros[contador++] = {"0160", "Introduccion a las finanzas", "Hugo Poma", 1, 2018, "Economia", "Finanzas"};
    libros[contador++] = {"0161", "Finanzas corporativas", "Lorena Huamani", 2, 2019, "Economia", "Finanzas"};
    libros[contador++] = {"0162", "Mercado de capitales", "Jaime Chura", 1, 2020, "Economia", "Finanzas"};
    libros[contador++] = {"0163", "Inversiones financieras", "Lucero Lazo", 2, 2021, "Economia", "Finanzas"};
    libros[contador++] = {"0164", "Riesgo y rendimiento", "Victor Caceres", 1, 2022, "Economia", "Finanzas"};

    // Economia - Contabilidad
    libros[contador++] = {"0165", "Contabilidad general", "Roxana Nina", 1, 2018, "Economia", "Contabilidad"};
    libros[contador++] = {"0166", "Contabilidad financiera", "Luis Huayta", 2, 2019, "Economia", "Contabilidad"};
    libros[contador++] = {"0167", "Contabilidad de costos", "Paola Rojas", 1, 2020, "Economia", "Contabilidad"};
    libros[contador++] = {"0168", "Contabilidad gerencial", "Juliana Chambi", 2, 2021, "Economia", "Contabilidad"};
    libros[contador++] = {"0169", "Estados financieros", "Erick Mamani", 1, 2022, "Economia", "Contabilidad"};

    // Ingenieria - Civil
    libros[contador++] = {"0170", "Fundamentos de ingenieria civil", "Luis Cardenas", 1, 2018, "Ingenieria", "Civil"};
    libros[contador++] = {"0171", "Diseño estructural basico", "Ana Rojas", 2, 2019, "Ingenieria", "Civil"};
    libros[contador++] = {"0172", "Construccion de carreteras", "Julio Pacheco", 1, 2020, "Ingenieria", "Civil"};
    libros[contador++] = {"0173", "Mecanica de suelos", "Rosa Luyo", 3, 2021, "Ingenieria", "Civil"};
    libros[contador++] = {"0174", "Hormigon armado", "Carlos Ninanya", 1, 2022, "Ingenieria", "Civil"};

    // Ingenieria - Mecanica
    libros[contador++] = {"0175", "Termodinamica basica", "Oscar Mamani", 1, 2019, "Ingenieria", "Mecanica"};
    libros[contador++] = {"0176", "Resistencia de materiales", "Lucia Vargas", 2, 2020, "Ingenieria", "Mecanica"};
    libros[contador++] = {"0177", "Mecanica de fluidos", "Pedro Nina", 3, 2021, "Ingenieria", "Mecanica"};
    libros[contador++] = {"0178", "Maquinas termicas", "Diana Quispe", 1, 2022, "Ingenieria", "Mecanica"};
    libros[contador++] = {"0179", "Diseño de maquinas", "Hector Ancco", 2, 2023, "Ingenieria", "Mecanica"};

    // Ingenieria - Electrica
    libros[contador++] = {"0180", "Circuitos electricos", "Cesar Ramos", 1, 2018, "Ingenieria", "Electrica"};
    libros[contador++] = {"0181", "Maquinas electricas", "Natalia Huamani", 2, 2020, "Ingenieria", "Electrica"};
    libros[contador++] = {"0182", "Electrotecnia basica", "Luis Chahuares", 1, 2019, "Ingenieria", "Electrica"};
    libros[contador++] = {"0183", "Instalaciones electricas", "Veronica Salas", 3, 2021, "Ingenieria", "Electrica"};
    libros[contador++] = {"0184", "Transformadores", "Hugo Quispe", 2, 2022, "Ingenieria", "Electrica"};

    // Ingenieria - Sistemas
    libros[contador++] = {"0185", "Programacion en C++", "Fernando Quispe", 1, 2018, "Ingenieria", "Sistemas"};
    libros[contador++] = {"0186", "Base de datos relacional", "Roxana Calla", 2, 2019, "Ingenieria", "Sistemas"};
    libros[contador++] = {"0187", "Ingenieria de software", "Carlos Vizcarra", 3, 2020, "Ingenieria", "Sistemas"};
    libros[contador++] = {"0188", "Sistemas operativos", "Isabel Nina", 1, 2021, "Ingenieria", "Sistemas"};
    libros[contador++] = {"0189", "Redes de computadoras", "Jaime Chura", 2, 2022, "Ingenieria", "Sistemas"};

    // Ingenieria - Industrial
    libros[contador++] = {"0190", "Gestion de calidad", "Erika Vilca", 1, 2018, "Ingenieria", "Industrial"};
    libros[contador++] = {"0191", "Logistica y produccion", "Jorge Caceres", 2, 2019, "Ingenieria", "Industrial"};
    libros[contador++] = {"0192", "Investigacion de operaciones", "Carla Ludeña", 3, 2020, "Ingenieria", "Industrial"};
    libros[contador++] = {"0193", "Seguridad industrial", "Walter Huamani", 1, 2021, "Ingenieria", "Industrial"};
    libros[contador++] = {"0194", "Gestion de procesos", "Ines Paredes", 2, 2022, "Ingenieria", "Industrial"};

    // Medicina - Anatomia
    libros[contador++] = {"0195", "Anatomia humana basica", "Luis Huamani", 1, 2018, "Medicina", "Anatomia"};
    libros[contador++] = {"0196", "Atlas de anatomia", "Rosa Quispe", 2, 2020, "Medicina", "Anatomia"};
    libros[contador++] = {"0197", "Anatomia para estudiantes", "Jorge Apaza", 3, 2019, "Medicina", "Anatomia"};
    libros[contador++] = {"0198", "Sistema oseo", "Elena Paredes", 1, 2021, "Medicina", "Anatomia"};
    libros[contador++] = {"0199", "Anatomia del sistema nervioso", "Carmen Luyo", 2, 2022, "Medicina", "Anatomia"};

    // Medicina - Fisiologia
    libros[contador++] = {"0200", "Fisiologia humana", "Lucia Valverde", 1, 2018, "Medicina", "Fisiologia"};
    libros[contador++] = {"0201", "Fundamentos de fisiologia", "Oscar Mamani", 2, 2020, "Medicina", "Fisiologia"};
    libros[contador++] = {"0202", "Fisiologia del sistema digestivo", "Sandra Huayta", 1, 2021, "Medicina", "Fisiologia"};
    libros[contador++] = {"0203", "Fisiologia cardiovascular", "Victor Ancco", 2, 2022, "Medicina", "Fisiologia"};
    libros[contador++] = {"0204", "Fisiologia pulmonar", "Mercedes Chuquimia", 1, 2019, "Medicina", "Fisiologia"};

    // Medicina - Farmacologia
    libros[contador++] = {"0205", "Introduccion a la farmacologia", "Daniela Vizcarra", 1, 2020, "Medicina", "Farmacologia"};
    libros[contador++] = {"0206", "Farmacos esenciales", "Andres Ramos", 2, 2021, "Medicina", "Farmacologia"};
    libros[contador++] = {"0207", "Manual de farmacologia", "Veronica Zevallos", 1, 2022, "Medicina", "Farmacologia"};
    libros[contador++] = {"0208", "Farmacologia clinica", "Ernesto Guzman", 1, 2019, "Medicina", "Farmacologia"};
    libros[contador++] = {"0209", "Farmacocinetica basica", "Milagros Poma", 2, 2020, "Medicina", "Farmacologia"};

    // Medicina - General
    libros[contador++] = {"0210", "Principios de medicina general", "Isabel Flores", 1, 2018, "Medicina", "General"};
    libros[contador++] = {"0211", "Diagnostico clinico", "Felix Paredes", 2, 2019, "Medicina", "General"};
    libros[contador++] = {"0212", "Tratamiento ambulatorio", "Ruben Chambi", 1, 2020, "Medicina", "General"};
    libros[contador++] = {"0213", "Medicina preventiva", "Cecilia Asto", 2, 2021, "Medicina", "General"};
    libros[contador++] = {"0214", "Salud publica", "Norma Chahuares", 1, 2022, "Medicina", "General"};

    // Idioma - Ingles
    libros[contador++] = {"0215", "Guia de Ingles", "Maria Lopez", 1, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"0216", "Manual de Ingles", "Maria Lopez", 2, 2021, "Idioma", "Ingles"};
    libros[contador++] = {"0217", "Aprende Ingles", "Maria Lopez", 1, 2022, "Idioma", "Ingles"};
    libros[contador++] = {"0218", "Curso basico de Ingles", "Maria Lopez", 3, 2020, "Idioma", "Ingles"};
    libros[contador++] = {"0219", "Introduccion a Ingles", "Maria Lopez", 1, 2021, "Idioma", "Ingles"};

    // Idioma - Frances
    libros[contador++] = {"0220", "Guia de Frances", "Jean Dupont", 1, 2020, "Idioma", "Frances"};
    libros[contador++] = {"0221", "Manual de Frances", "Jean Dupont", 2, 2021, "Idioma", "Frances"};
    libros[contador++] = {"0222", "Aprende Frances", "Jean Dupont", 1, 2022, "Idioma", "Frances"};
    libros[contador++] = {"0223", "Curso basico de Frances", "Jean Dupont", 3, 2020, "Idioma", "Frances"};
    libros[contador++] = {"0224", "Introduccion a Frances", "Jean Dupont", 1, 2021, "Idioma", "Frances"};

    // Idioma - Quechua
    libros[contador++] = {"0225", "Guia de Quechua", "Rumi Huaman", 1, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"0226", "Manual de Quechua", "Rumi Huaman", 2, 2021, "Idioma", "Quechua"};
    libros[contador++] = {"0227", "Aprende Quechua", "Rumi Huaman", 1, 2022, "Idioma", "Quechua"};
    libros[contador++] = {"0228", "Curso basico de Quechua", "Rumi Huaman", 3, 2020, "Idioma", "Quechua"};
    libros[contador++] = {"0229", "Introduccion a Quechua", "Rumi Huaman", 1, 2021, "Idioma", "Quechua"};

    // Idioma - Aleman
    libros[contador++] = {"0230", "Guia de Aleman", "Hans Becker", 1, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"0231", "Manual de Aleman", "Hans Becker", 2, 2021, "Idioma", "Aleman"};
    libros[contador++] = {"0232", "Aprende Aleman", "Hans Becker", 1, 2022, "Idioma", "Aleman"};
    libros[contador++] = {"0233", "Curso basico de Aleman", "Hans Becker", 3, 2020, "Idioma", "Aleman"};
    libros[contador++] = {"0234", "Introduccion a Aleman", "Hans Becker", 1, 2021, "Idioma", "Aleman"};

    // Idioma - Chino
    libros[contador++] = {"0235", "Guia de Chino", "Li Zhang", 1, 2020, "Idioma", "Chino"};
    libros[contador++] = {"0236", "Manual de Chino", "Li Zhang", 2, 2021, "Idioma", "Chino"};
    libros[contador++] = {"0237", "Aprende Chino", "Li Zhang", 1, 2022, "Idioma", "Chino"};
    libros[contador++] = {"0238", "Curso basico de Chino", "Li Zhang", 3, 2020, "Idioma", "Chino"};
    libros[contador++] = {"0239", "Introduccion a Chino", "Li Zhang", 1, 2021, "Idioma", "Chino"};

}
