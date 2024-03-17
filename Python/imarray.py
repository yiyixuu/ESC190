from PIL import Image
im = Image.open('/Users/yiyixu/Documents/First Year/Winter/ESC190/Python/HJoceanSmall.png')
pixels = list(im.getdata())

print(pixels[:10])