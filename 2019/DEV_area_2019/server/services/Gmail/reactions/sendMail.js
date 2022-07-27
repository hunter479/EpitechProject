nodeMailer = require('nodemailer');

class sendMail {

    async ask(user, auto_index, co_info, co_index) {
        var parsed = JSON.parse(user.automation[auto_index].reaction.data);
        console.log('GMAIL MAGGLE', parsed);
        let transporter = nodeMailer.createTransport({
            host: 'smtp.gmail.com',
            port: 465,
            secure: true,
            auth: {
                user: 'desp.eddy@gmail.com',
                pass: 'millaydy97425' // J'vous vois à prendre le mdp la
            }
        });
        let mailOptions = {
            from: '"Area" <desp.eddy@gmail.com>', // sender address
            to: parsed.receiver, // list of receivers
            subject: "Automated mail", // Subject line
            text: "Automated mail", // plain text body
            html: parsed.content // html body
        };

        await transporter.sendMail(mailOptions, async(error, info) => {
            if (error) {
                return console.log(error);
            }
            console.log('Message %s sent: %s', info.messageId, info.response);
            });
    }
};

module.exports = sendMail;