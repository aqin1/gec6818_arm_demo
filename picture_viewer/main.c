#include "main.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        perror("argc != 2");
        return -1;
    }

    node_t picture_link = NULL;
    link_create(&picture_link);

    scan_picture(argv[1], picture_link);

    int picture_num = link_length(picture_link);
    printf("picture quantity: %d\n",picture_num);

    int count = 0;
    int ret = 0;
    while(1)
    {
        ret = left_right();
		if(ret == MOVE_LEFT || ret > 400)
		{
            count++;
            if(count > picture_num)
            {
                count = 1;
            }
            clear_sc();
			show_bmp(node_get(picture_link, count)->item, 0, 0);
            printf("no.%d\n\n",count);
        }
        else if(ret == MOVE_RIGHT || ret <= 400)
		{
            count--;
            if(count <= 0)
            {
                count = picture_num;
            }
            clear_sc();
			show_bmp(node_get(picture_link, count)->item, 0, 0);
            printf("no.%d\n\n",count);
		}
    }
    link_destroy(&picture_link);

    return 0;
}