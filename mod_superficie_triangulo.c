#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

/* El Manejador (Handler): Aquí ocurre la magia */
static int superficie_triangulo_handler(request_rec *r)
{
    // Solo respondemos si la petición es para "superficie-triangulo"
    if (strcmp(r->handler, "superficie-triangulo")) {
        return DECLINED;
    }

    // Le decimos al navegador que vamos a enviar HTML

    //ap_set_content_type(r, "text/html");
    ap_set_content_type(r, "text/html; charset=utf-8");
    // Obtenemos los argumentos de la URL (ej: ?base=10&altura=5)
    apr_table_t *params;
    ap_args_to_table(r, &params);
    
    const char *base_str = apr_table_get(params, "base");
    const char *altura_str = apr_table_get(params, "altura");

    ap_rputs("<html><body><h1>Resultado del Cálculo para Margarito</h1>", r);

    if (base_str && altura_str) {
        float base = atof(base_str);
        float altura = atof(altura_str);
        float area = (base * altura) / 2;
        ap_rprintf(r, "<p>La superficie del triángulo es: <b>%.2f</b></p>", area);
    } else {
        ap_rputs("<p>Error: Faltan datos (base o altura).</p>", r);
    }

    ap_rputs("<br><a href='/triangulo/'>Volver</a></body></html>", r);
    return OK;
}

/* Registro del módulo en los Hooks de Apache */
static void register_hooks(apr_pool_t *p)
{
    ap_hook_handler(superficie_triangulo_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* Estructura que Apache busca al cargar el .so */
module AP_MODULE_DECLARE_DATA superficie_triangulo_module = {
    STANDARD20_MODULE_STUFF,
    NULL, NULL, NULL, NULL, NULL,
    register_hooks
};