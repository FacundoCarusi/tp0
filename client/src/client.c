#include "client.h"
#include "utils.h"



int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	t_log* logNuevo = log_create("tp0.log", "CLIENTE", 1, LOG_LEVEL_DEBUG);

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	log_debug(logNuevo, "Hola! Soy un log");
	

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	config = config_create( "cliente.config");

	if (config == NULL) {												//si falla la creacion del config, aborto!
		printf("Error al abrir el archivo de configuracion\n");
		abort();
	}
	valor = config_get_string_value(config, "CLAVE");
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");  				//string para que no sea cambiado en ningun momento del programa, nashe

	// Loggeamos el valor de config
	log_debug(logNuevo, "El valor de la clave es: %s", valor);   		//uso logNuevo pq es el log que tenia creado antes
	log_debug(logNuevo, "La ip es: %s", ip);							// %s es para que espere un valor que le paso en el proximo parametro, osea la ip
	log_debug(logNuevo, "El puerto es: %s", puerto);
	// No olvides liberar el config antes de continuar
	config_destroy(config);												//destruyo la config para que no quede ocupando memoria, ya que no la necesito mas
	log_destroy(logNuevo);												//destruyo el log para que no quede ocupando memoria, ya que no la necesito mas



	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
