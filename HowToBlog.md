# Writing a blog post on the website
## (some HTML knowledge assumed, but you can get away without doing much)
### Sorry if this is pitched at the wrong level, I have no idea how comfortable you guys are with HTML/GitHub but thought either way it would be interesting to write some documentation

As of 7 Feb there are 3 blog posts: "New website", "Training week" and "Meet the team". Yhe final two are already in place but need more content

#### Content

- The best way to start (from the GitHub repo home page) is to go into /blog and copy all the  info from one of the files (copy and paste works) into a new file in /blog 
called *post-name*.html 

- Then on that HTML file (you can edit in GitHub or may prefer your own editor) go to line 93 (or somewhere near there) where the `<div id="body">` starts; 
everything inside this `<div>` is the content of the blog post, the rest can be left alone. 
  - the commenting before the end of the div was for stuff that was in place before
and could maybe(?) reappear, sorry I know it doesn't look very nice

- Edit this stuff to make the blog as you wish (including the date inside <span> and the image source - you can either upload an image into the /images folder or link a URL)
  - NB currently need to use separate `<p>` elements if you want the paragraphs to have a line break between them.

- Save that and upload/copy/make sure it's in the /blog folder (if you want to check the result before you can download the whole repo and click on any of the HTML
files, it should display on your browser as if it's a website)


#### Making sure the post is visible from blog.html

- Go to blog.html (in GitHub or editor), find the `<div id="body">` as before (also around line 93) and look at the list structure

- For your new post, you can just copy one of the list items (everything inside the `<li> ... </li>`tags including the tags) and paste it directly before the first one (ie after `<ul>`on line 98). Things that need to be changed are:
  - both the `href=""` tags, these are the link to your new HTML page
  - The image source (same one as you used in the blog post)
  - The title inside `<h1>` and the date inside `<span>`
  - Description of the post content (or the first paragpraph) inside `<p>`
  
- Now scroll down to the `<h1>RECENT POSTS</h1>` section, and again copy the list structure by adding a new item at the start of the list (C+P should be useful)
  - Change the link inside `href`to your new page and change the image source to the same as the other two occasions
  
Aaaaand you're **done**!

Sorry if that was a bit painful, if it is too much effort then I'm happy to convert any pre-written blog posts into the format for the website

If some of the image formatting comes out dodgy you could add some styles to the elements, a lot of the related elements have had a few things like `style="width:auto;"` in them, hopefully that will solve any problems!



##### Once this is all going smoothly we can do other stuff like changing the featured posts and linking the science pages to relevant blog posts :)

