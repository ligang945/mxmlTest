#include "mxml.h"
#include "stdio.h"

int main()
{
    mxml_node_t *xml;
    mxml_node_t *data; 
    mxml_node_t *node;
    mxml_node_t *group;

    xml = mxmlNewXML("1.0");

    data = mxmlNewElement(xml, "data");

    node = mxmlNewElement(data, "node");
    mxmlNewText(node, 0, "val1");
    node = mxmlNewElement(data, "node");
    mxmlNewText(node, 0, "val2");
    node = mxmlNewElement(data, "node");
    mxmlNewText(node, 0, "val3");

    group = mxmlNewElement(data, "group");

    node = mxmlNewElement(group, "node");
    mxmlNewText(node, 0, "val4");
    node = mxmlNewElement(group, "node");
    mxmlNewText(node, 0, "val5");
    node = mxmlNewElement(group, "node");
    mxmlNewText(node, 0, "val6");

    node = mxmlNewElement(data, "node");
    mxmlNewText(node, 0, "val7");
    node = mxmlNewElement(data, "node");
    mxmlNewText(node, 0, "val8");

    FILE *fp;
    fp = fopen("tmp.xml", "w");
    mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
    fclose(fp);

    system("xmllint --format tmp.xml  --output eg.xml");
    system("rm tmp.xml");

    printf("Hello mxml\n");
    return 0;
}
